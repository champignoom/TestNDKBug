package com.champignoom.testndkbug;

public class NDKWrapper {
    static {
        System.loadLibrary("native-lib");
    }
    static native void run_native();
}
