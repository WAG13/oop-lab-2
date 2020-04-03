#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    facade.addPlotTime(ui->plot_time);
    facade.addPlotMemory(ui->plot_memo);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    facade.addInfo(ui->comboBox->currentIndex(),ui->num_elem->value(),ui->step->value(),ui->num_sorts->value());

    /* Test */
    //TODO: remove
/*
    Sorting<int>* sortAlgorithm = new MergeSort<int>();
    DataGenerator<int>* dataGen = new RandomDataGenerator<int>();

    MemoryTrackerHook* memoryTracker = new MemoryTrackerHook();
    TimeTrackerHook* timeTracker = new TimeTrackerHook();

    TestBuilder test;
    test.setSortAlgorithm(sortAlgorithm)
            //Add parameters
            ->setStartElementCount(100)
            ->setStepSize(10000)
            ->setStepCount(5)
            ->setDataGenerator(dataGen)
            //Add hooks
            ->addDiagnosticsHook(memoryTracker)
            ->addDiagnosticsHook(timeTracker)
            //Run
            ->run();

    //Get results of hooks
    vector<Point> bytesUsed = memoryTracker->getBytesUsed();
    for(const Point& p : bytesUsed) {
        qDebug() << p.x << " elements: " << p.y << " bytes used" << endl;
    }

    vector<Point> durations = timeTracker->getDurationsSeconds();
    for(const Point& p : durations) {
        qDebug() << p.x << " elements: " << p.y << " seconds" << endl;
    }


    delete memoryTracker;
    delete sortAlgorithm;
    delete dataGen;
    */

}


