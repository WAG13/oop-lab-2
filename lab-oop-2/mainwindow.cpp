#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <Diagnostics/MemoryTrackerHook.h>
#include <SortingAlgorithms/SortingAlgorithms.h>
#include <SortingAlgorithms/Random.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int size = getRandomInt(50000, 200000);
    std::vector<int> integers = getRandomVector(0, 10000, size);
    MergeSort<int> sort;
    sort.setComparator([](int const &left, int const &right) { return left < right; });

    MemoryTrackerHook::trackMemory = true;
    MemoryTrackerHook::bytesUsed = 0;
    qDebug() << "Sorting " << integers.size() << " ints " << endl;
    qDebug() << "Start sorting" << endl;

    sort.sort(integers, 0, integers.size() - 1);


    qDebug() << "Finish sorting" << endl;
    qDebug() << "Memory used: " << MemoryTrackerHook::bytesUsed << endl;
//    test::trackMemory = false;

    ui->label->setText(QString::number(++t));
}
