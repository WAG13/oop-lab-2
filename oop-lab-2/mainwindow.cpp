#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "QDebug"
/*
#include "Diagnostics/TestBuilder.h"
#include "Diagnostics/DataGenerator.h"
#include "Diagnostics/MemoryTrackerHook.h"
#include "Diagnostics/TimeTrackerHook.h"

#include "SortingAlgorithms/SortingAlgorithms.h"

#include <vector>
#include <memory>*/

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    preparePlot(ui->plot_numb_time,"number of elements","time");
    preparePlot(ui->plot_time_memo,"time","memory");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    /* Test */
    /* TODO: remove

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
    // generate some data:
    QVector<double> x;
    QVector<double> y;
    // generate some data for example
    for (int i = 0; i < ui->num_sorts->value(); ++i)
    {
      x.push_back(i*ui->step->value()+ui->num_elem->value()) ;
      y.push_back(log(x[i]));
    }
    // refresh plots
    clearPlot(ui->plot_numb_time);
    clearPlot(ui->plot_time_memo);
    // adding data
    setPlot(ui->plot_numb_time,x,y);
    setPlot(ui->plot_time_memo,x,y);
    // draws aproximation function
    addAproximation(ui->plot_numb_time,x,y);
}

void MainWindow::preparePlot(QCustomPlot *plot, QString x_axis_name, QString y_axis_name){
    QColor myWhite(220,220,220);
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    /* axis */
    plot->xAxis->setBasePen(QPen(myWhite, 1));
    plot->yAxis->setBasePen(QPen(myWhite, 1));
    plot->xAxis->setTickPen(QPen(myWhite, 1));
    plot->yAxis->setTickPen(QPen(myWhite, 1));
    plot->xAxis->setSubTickPen(QPen(myWhite, 1));
    plot->yAxis->setSubTickPen(QPen(myWhite, 1));
    plot->xAxis->setTickLabelColor(myWhite);
    plot->yAxis->setTickLabelColor(myWhite);
    plot->xAxis->setLabelFont(QFont("Segoe UI"));
    plot->yAxis->setLabelFont(QFont("Segoe UI"));
    plot->xAxis->setLabelColor(myWhite);
    plot->yAxis->setLabelColor(myWhite);
    plot->xAxis->setLabel(x_axis_name);
    plot->yAxis->setLabel(y_axis_name);

    plot->yAxis->grid()->setSubGridVisible(true);
    plot->xAxis->grid()->setVisible(true);
    plot->yAxis->grid()->setPen(QPen(QColor(140, 130, 130), 0, Qt::SolidLine));
    plot->xAxis->grid()->setPen(QPen(QColor(140, 130, 130), 0, Qt::DotLine));
    plot->yAxis->grid()->setSubGridPen(QPen(QColor(140, 130, 130), 0, Qt::DotLine));

    /*background*/
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(90, 80, 80));
    plotGradient.setColorAt(1, QColor(60, 50, 50));
    plot->setBackground(plotGradient);
}

void MainWindow::clearPlot(QCustomPlot *plot) {
    // deleting all data on plot
    for( int g=0; g<plot->graphCount(); g++ )
        plot->graph(g)->data()->clear();
    // refresh
    plot->replot();
}

void MainWindow::setPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth) {
    // create graph and assign data to it:
    plot->addGraph();
    plot->graph(depth)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(QColor(255, 108, 0, 255)), 9));
    plot->graph(depth)->setPen(QPen(QColor(255, 108, 0, 255)));
    plot->graph(depth)->setBrush(QBrush(QColor(255, 108, 0, 25)));
    plot->graph(depth)->setData(x, y);
    // set axes ranges, so we see all data:
    plot->xAxis->setRange(x[0], x[x.size()-1]);
    plot->yAxis->setRange(y[0], y[y.size()-1]);
    // refresh
    plot->replot();
}

void MainWindow::addAproximation(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth) {
    // create graph and assign data to it:
    plot->addGraph();
    plot->graph(depth)->setPen(QPen(QColor(60, 108, 255, 255)));
    plot->graph(depth)->setData(x, y);
    // set axes ranges, so we see all data:
    plot->xAxis->setRange(x[0], x[x.size()-1]);
    plot->yAxis->setRange(y[0], y[y.size()-1]);
    // refresh
    plot->replot();
}
