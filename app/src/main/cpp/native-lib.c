#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>

#ifdef TEST_HOST
#define printlog(...) fprintf(stderr, __VA_ARGS__)
#else
#include <jni.h>
#include <android/log.h>
#define printlog(...) __android_log_print(ANDROID_LOG_DEBUG, "TestNDKBug", __VA_ARGS__)
#endif

static const struct timespec DURATION = { .tv_sec = 0, .tv_nsec = 200LL*1000*1000 };
static const struct timespec DURATION5 = { .tv_sec = 1, .tv_nsec = 0 };

static void *do_thread(void *_arg) {
    for (int i=0; i<10; ++i) {
        printlog("loop %d\n", i);
        if (nanosleep(&DURATION, NULL)) {
            perror("nanosleep thread");
        }
    }
    return NULL;
}

static void signal_handler(int _sig) {
    fprintf(stderr, "signal received\n");
    pthread_exit(NULL);
}

void do_main() {
    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_restorer = NULL;
    sa.sa_sigaction = NULL;
    sa.sa_handler = signal_handler;
    if (sigemptyset(&sa.sa_mask)) {
        perror("sigemptyset");
        exit(1);
    }
    if (sigaction(SIGUSR1, &sa, NULL)) {
        perror("sigaction");
        exit(1);
    }

    pthread_t pid;
    if (pthread_create(&pid, NULL, do_thread, NULL)) {
        perror("pthread_create");
        exit(1);
    }

    if (nanosleep(&DURATION5, NULL)) {
        perror("nanosleep main");
    }

    if (pthread_kill(pid, SIGUSR1)) {
        perror("pthread_kill");
        exit(1);
    }

    if (pthread_join(pid, NULL)) {
        perror("pthread_join");
    }
}

#ifdef TEST_HOST
int main() {
    do_main();
    return 0;
}
#else
JNIEXPORT void JNICALL
Java_com_champignoom_testndkbug_NDKWrapper_run_1native(JNIEnv *env, jclass clazz) {
    do_main();
}
#endif

