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
#include "Approximation/ConstantApproximator.h"
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

/*!
 * \brief The Facade class
 */
class Facade
{
public:
    Facade(){}
    Facade(QCustomPlot *plot_t, QCustomPlot *plot_m);
    ~Facade();
    void addPlotTime(QCustomPlot *plot);
    void addPlotMemory(QCustomPlot *plot);
    void addInfoBox(QTextEdit *info);
    void runSimulation(int sorting_type, int data_type, int elem_numb, int step, int sort_numb);
    int getNumberElements() const {return elem_numb;}
    int getNumberSorts() const {return sort_numb;}
    int getStep() const {return step;}
    Function* getTimeFunc() const {return timeFunc;}
    Function* getMemoryFunc() const {return memoryFunc;}
private:
    QCustomPlot *plot_time;
    QCustomPlot *plot_memo;
    QTextEdit *info;
    const int accuracy = 10000;
    int elem_numb = 0;
    int sort_numb = 0;
    int step = 0;
    Sorting<int>* sortAlgorithm;
    DataGenerator<int>* dataGen;
    Function* timeFunc;
    Function* memoryFunc;

    void preparePlot(QCustomPlot *plot, QString x_axis_name, QString y_axis_name);
    void setSortingType(int index);
    void setDataType(int index);
    void runSorting();
    Function* getBestApproximation(const vector<Point>& points);
    void clearPlot(QCustomPlot *plot);
    void addPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth=0);
    void addAproximationPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth=1);
    void drawPlots(vector<Point> bytesUsed, vector<Point> durations);
};

#endif // VIEWINFO_H
