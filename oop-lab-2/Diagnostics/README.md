## Diagnostics

The Diagnostics library uses a TestBuilder and combinations of Hooks. These Hooks measure different values: e.g. time and used memory.

Example usage:
```c++

    MemoryTrackerHook* memoryTracker = new MemoryTrackerHook();
    Sorting<int>* sortAlgorithm = new MergeSort<int>();
    DataGenerator<int>* dataGen = new RandomDataGenerator<int>();

    TestBuilder test;
    test.setSortAlgorithm(sortAlgorithm)
            //Add parameters
            ->setStartElementCount(100);
            ->setStepSize(10000)
            ->setStepCount(5)
            ->setDataGenerator(dataGen)
            //Add hooks
            ->addDiagnosticsHook(memoryTracker)
            ->addDiagnosticsHook(...)
            //Run
            ->run();

    //Get results of hooks
    vector<Point> bytesUsed = memoryTracker->getBytesUsed();
    for(const Point& p : bytesUsed) {
        qDebug() << p.x << " elements: " << p.y << " bytes used" << endl;
    }
```
