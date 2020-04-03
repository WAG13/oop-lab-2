#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "Diagnostics/MemoryTrackerHook.h"
#include "SortingAlgorithms/SortingAlgorithms.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // give the axes some labels:
    ui->plot_numb_time->xAxis->setLabel("number of elements");
    ui->plot_numb_time->yAxis->setLabel("time");
    ui->plot_time_memo->xAxis->setLabel("time");
    ui->plot_time_memo->yAxis->setLabel("memory");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    /**/
    // generate some data:
    QVector<double> x(101), y(101);
    for (int i = 0; i < 101; ++i)
    {
      x[i] = i + ui->num_elem->value() ;
      y[i] = x[i]*3;
    }

    // create graph and assign data to it:
    ui->plot_numb_time->addGraph();
    ui->plot_numb_time->graph(0)->setPen(QPen(QColor(255, 108, 0, 255)));
    ui->plot_numb_time->graph(0)->setBrush(QBrush(QColor(255, 108, 0, 25)));
    ui->plot_numb_time->graph(0)->setData(x, y);

    // set axes ranges, so we see all data:
    ui->plot_numb_time->xAxis->setRange(x[0], x[100]);
    ui->plot_numb_time->yAxis->setRange(y[0], y[100]);
    ui->plot_numb_time->replot();

    // create graph and assign data to it:
    ui->plot_time_memo->addGraph();
    ui->plot_time_memo->graph(0)->setPen(QPen(QColor(255, 108, 0, 255)));
    ui->plot_time_memo->graph(0)->setBrush(QBrush(QColor(255, 108, 0, 25)));
    ui->plot_time_memo->graph(0)->setData(x, y);

    // set axes ranges, so we see all data:
    ui->plot_time_memo->xAxis->setRange(x[0], x[100]);
    ui->plot_time_memo->yAxis->setRange(y[0], y[100]);
    ui->plot_time_memo->replot();
}