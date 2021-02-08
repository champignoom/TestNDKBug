Result of InstrumentedTest.test:
```
...
2021-02-08 15:36:48.273 21420-21454/com.champignoom.testndkbug I/TestRunner: started: test(com.champignoom.testndkbug.InstrumentedTest)
2021-02-08 15:36:48.279 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 0
2021-02-08 15:36:48.479 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 1
2021-02-08 15:36:48.679 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 2
2021-02-08 15:36:48.880 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 3
2021-02-08 15:36:49.082 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 4
2021-02-08 15:36:49.283 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 5
2021-02-08 15:36:49.483 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 6
2021-02-08 15:36:49.684 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 7
2021-02-08 15:36:49.885 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 8
2021-02-08 15:36:50.085 21420-21456/com.champignoom.testndkbug D/TestNDKBug: loop 9
2021-02-08 15:36:50.286 21420-21454/com.champignoom.testndkbug I/TestRunner: finished: test(com.champignoom.testndkbug.InstrumentedTest)
...
```

Result of host test (`gcc -DTEST_HOST app/src/main/cpp/native-lib.c -lpthread -std=gnu11 -o ./test-ndk-bug && ./test-ndk-bug`):
```
loop 0
loop 1
loop 2
loop 3
loop 4
signal received
```
