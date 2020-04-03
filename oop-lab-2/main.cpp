#include "mainwindow.h"
#include <vector>

#include "Approximation/Point.h"
#include "Approximation/LogarithmicApproximator.h"
#include "Approximation/ApproximationData.h"

#include "Diagnostics/MemoryTrackerHook.h"

#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    //Test 1
    LogarithmicApproximator logarithmicApproximator;

    ApproximationData data = logarithmicApproximator.approximate({ Point(4, 2), Point(8, 3), Point(2, 1) });

    //print koeficients a,b of y=alogx+b
    for (double koef : data.function->getKoefs()) {
        qDebug() << koef << " ";
    }

    qDebug() << endl;
    qDebug() << data.standartDeviation;



    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
