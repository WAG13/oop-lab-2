#include "facade.h"

Facade::Facade(QCustomPlot *plot1, QCustomPlot *plot2):plot_time(plot1),plot_memo(plot2) {
    preparePlot(plot_time, "number of elements", "time, seconds");
    preparePlot(plot_memo, "number of elements", "memory, bytes");
}
void Facade::addPlotTime(QCustomPlot *plot){
    plot_time=plot;
    preparePlot(plot_time, "number of elements", "time, seconds");
}
void Facade::addPlotMemory(QCustomPlot *plot){
    plot_memo=plot;
    preparePlot(plot_memo, "number of elements", "memory, bytes");
}

void Facade::addInfo(int sort_type, int elem_numb, int step, int sort_numb){
    this->elem_numb = elem_numb;
    this->step = step;
    this->sort_numb = sort_numb;
    setSortingType(sort_type);
    runSorting();
}

void Facade::setSortingType(int index){
    switch ( index )
          {
             case 0:
                sortAlgorithm = new BubbleSort <int>();
                break;
             case 1:
                sortAlgorithm = new SelectionSort <int>();
                break;
             case 2:
                sortAlgorithm = new InsertionSort <int>();
                break;
             case 3:
                sortAlgorithm = new QuickSort<int>(new MiddlePivot<int>());
                break;
             case 4:
                sortAlgorithm = new QuickSort<int>(new MedianOfThreePivot<int>());
                break;
             case 5:
                sortAlgorithm = new QuickSort<int>(new RandomPivot<int>());
                break;
             case 6:
                sortAlgorithm = new MergeSort <int>();
                break;
             case 7:
                sortAlgorithm = new ShellSort<int>(new ShellStrategy());
                break;
             case 8:
                sortAlgorithm = new ShellSort<int>(new HibbardStrategy());
                break;
             case 9:
                sortAlgorithm = new ShellSort<int>(new SedgewickStrategy());
                break;
             case 10:
                sortAlgorithm = new ShellSort<int>(new CiuraStrategy());
                break;
             default:
                sortAlgorithm = new BubbleSort <int>();
          }
}

void Facade::runSorting(){
    QVector<double> number;
    QVector<double> time;
    QVector<double> memory;

    DataGenerator<int>* dataGen = new RandomDataGenerator<int>();
    MemoryTrackerHook* memoryTracker = new MemoryTrackerHook();
    TimeTrackerHook* timeTracker = new TimeTrackerHook();
    TestBuilder test;
    test.setSortAlgorithm(sortAlgorithm)
            //Add parameters
            ->setStartElementCount(elem_numb)
            ->setStepSize(step)
            ->setStepCount(sort_numb)
            ->setDataGenerator(dataGen)
            //Add hooks
            ->addDiagnosticsHook(memoryTracker)
            ->addDiagnosticsHook(timeTracker)
            //Run
            ->run();

    //Get results of hooks
    vector<Point> bytesUsed = memoryTracker->getBytesUsed();
    for(const Point& p : bytesUsed) {
        number.push_back(p.x);
        memory.push_back(p.y);
        qDebug() << p.x << " elements: " << p.y << " bytes used" << endl;
    }
    vector<Point> durations = timeTracker->getDurationsSeconds();
    for(const Point& p : durations) {
        time.push_back(p.y);
        qDebug() << p.x << " elements: " << p.y << " seconds" << endl;
    }

    clearPlot(plot_time);
    clearPlot(plot_memo);
    setPlot(plot_time, number, time);
    setPlot(plot_memo, number, memory);

    //runAproximation(plot_memo,);

    delete memoryTracker;
    delete sortAlgorithm;
    delete dataGen;
}

void Facade::runAproximation(){
    /*//Test 1
    LogarithmicApproximator logarithmicApproximator;

    ApproximationData data = logarithmicApproximator.approximate({ Point(4, 2), Point(8, 3), Point(2, 1) });

    //print koeficients a,b of y=alogx+b
    for (double koef : data.function->getKoefs()) {
        qDebug() << koef << " ";
    }

    qDebug() << endl;
    qDebug() << data.standartDeviation;
    */
}

void Facade::clearPlot(QCustomPlot *plot) {
    // deleting all data on plot
    for( int g=0; g<plot->graphCount(); g++ )
        plot->graph(g)->data()->clear();
    // refresh
    plot->replot();
}

void Facade::setPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth) {
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

void Facade::addAproximationPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth) {
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

void Facade::preparePlot(QCustomPlot *plot, QString x_axis_name, QString y_axis_name){
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
