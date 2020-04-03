#ifndef VIEWINFO_H
#define VIEWINFO_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "qcustomplot.h"

#include "Approximation/Point.h"
#include "Approximation/LinearApproximator.h"
#include "Approximation/QuadraticApproximator.h"
#include "Approximation/XLogXApproximator.h"
#include "Approximation/LogarithmicApproximator.h"
#include "Approximation/ApproximationData.h"
#include "Approximation/Functions/Function.h"

#include "Diagnostics/DataGenerator.h"
#include "Diagnostics/MemoryTracker.h"
#include "Diagnostics/MemoryTrackerHook.h"
#include "Diagnostics/TimeTrackerHook.h"
#include "Diagnostics/TestBuilder.h"
#include "SortingAlgorithms/SortingAlgorithms.h"
#include <vector>
#include <memory>

class Facade
{
public:
    Facade(){}
    Facade(QCustomPlot *plot1, QCustomPlot *plot2);
    ~Facade(){delete plot_time; delete plot_memo;}
    void addPlotTime(QCustomPlot *plot);
    void addPlotMemory(QCustomPlot *plot);
    void addInfo(int sorting_type, int elem_numb, int step, int sort_numb);

private:
    QCustomPlot *plot_time;
    QCustomPlot *plot_memo;
    int sorting_type = 0;
    int elem_numb = 0;
    int step = 0;
    int sort_numb = 0;
    Sorting<int>* sortAlgorithm;
    QVector<Point> data;

    void preparePlot(QCustomPlot *plot, QString x_axis_name, QString y_axis_name);
    void setSortingType(int index);
    void runSorting();
    Function* getBestApproximation(const vector<Point>& points);
    void clearPlot(QCustomPlot *plot);
    void setPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth=0);
    void addAproximationPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth=1);
};

#endif // VIEWINFO_H
