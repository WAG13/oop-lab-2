#include "facade.h"
#include <algorithm>
/*!
 * \brief Facade::Facade
 * \param plot_t
 * \param plot_m
 */
Facade::Facade(QCustomPlot *plot_t, QCustomPlot *plot_m) {
    addPlotTime(plot_t);
    addPlotMemory(plot_m);
}

/*!
 * \brief Facade::~Facade
 */
Facade::~Facade(){
    delete plot_time;
    delete plot_memo;
    delete timeFunc;
    delete memoryFunc;
}

/*!
 * \brief Facade::addPlotTime
 * \param plot
 */
void Facade::addPlotTime(QCustomPlot *plot){
    plot_time=plot;
    preparePlot(plot_time, "number of elements", "time, seconds");
}

/*!
 * \brief Facade::addPlotMemory
 * \param plot
 */
void Facade::addPlotMemory(QCustomPlot *plot){
    plot_memo=plot;
    preparePlot(plot_memo, "number of elements", "memory, bytes");
}

/*!
 * \brief Facade::addInfoBox
 * \param info
 */
void Facade::addInfoBox(QTextEdit *info){ this->info = info; }

/*!
 * \brief Facade::runSimulation
 * \param sort_type
 * \param elem_numb
 * \param step
 * \param sort_numb
 */
void Facade::runSimulation(int sort_type, int data_type, int elem_numb, int step, int sort_numb){
    this->elem_numb = elem_numb;
    this->step = step;
    this->sort_numb = sort_numb;
    setSortingType(sort_type);
    setDataType(data_type);
    info->clear();
    runSorting();
}

/*!
 * \brief Facade::setSortingType
 * \param index
 */
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

/*!
 * \brief Facade::setDataType
 * \param index
 */
void Facade::setDataType(int index){
    switch ( index )
          {
             case 0:
                dataGen = new RandomDataGenerator<int>();
                break;
             case 1:
                dataGen = new SortedAscendingDataGenerator<int>();
                break;
             default:
                dataGen = new SortedDescendingDataGenerator<int>();
          }
}

/*!
 * \brief Facade::runSorting
 */
void Facade::runSorting(){

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
    vector<Point> durations = timeTracker->getDurationsSeconds();
    timeFunc = getBestApproximation(durations);
    memoryFunc = getBestApproximation(bytesUsed);
    drawPlots(bytesUsed, durations);
    delete memoryTracker;
    delete dataGen;
}

/*!
 * \brief Facade::getBestApproximation
 * \param points
 * \return
 */
Function* Facade::getBestApproximation(const vector<Point>& points) {

    static unique_ptr<Approximator> linearApproximator = make_unique<LinearApproximator>();
    static unique_ptr<Approximator> logApproximator = make_unique<LogarithmicApproximator>();
    static unique_ptr<Approximator> quadraticApproximator = make_unique<QuadraticApproximator>();
    static unique_ptr<Approximator> xlogxApproximator = make_unique<XLogXApproximator>();
    static unique_ptr<Approximator> constantApproximator = make_unique<ConstantApproximator>();

    static vector<Approximator*> approximators = {
        linearApproximator.get(),
        logApproximator.get(),
        quadraticApproximator.get(),
        xlogxApproximator.get(),
        constantApproximator.get()
    };

    vector<ApproximationData> approximationResults;
    for(const auto& approximator : approximators) {
        ApproximationData data = approximator->approximate(points);
        approximationResults.push_back(data);
    }

    auto bestResult = std::min_element(
                approximationResults.begin(),
                approximationResults.end(),
                [](const ApproximationData& data1, const ApproximationData& data2) {
                            return data1.standartDeviation < data2.standartDeviation;
                        });

    return bestResult->function;
}

/*!
 * \brief Facade::clearPlot
 * \param plot
 */
void Facade::clearPlot(QCustomPlot *plot){
    // deleting all data on plot
    for( int g=0; g<plot->graphCount(); g++ )
        plot->graph(g)->data()->clear();
    // refresh
    plot->replot();
}

/*!
 * \brief Facade::addPlot
 * \param plot
 * \param x
 * \param y
 * \param depth
 */
void Facade::addPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth){
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

/*!
 * \brief Facade::addAproximationPlot
 * \param plot
 * \param x
 * \param y
 * \param depth
 */
void Facade::addAproximationPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, int depth){
    // create graph and assign data to it:
    plot->addGraph();
    plot->graph(depth)->setPen(QPen(QColor(60, 108, 255, 255)));
    plot->graph(depth)->setData(x, y);
    // set axes ranges, so we see all data:
    //plot->xAxis->setRange(x[0], x[x.size()-1]);
    //plot->yAxis->setRange(y[0], y[y.size()-1]);
    // refresh
    plot->replot();
}

/*!
 * \brief Facade::preparePlot
 * \param plot
 * \param x_axis_name
 * \param y_axis_name
 */
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

/*!
 * \brief Facade::drawPlots
 * \param bytesUsed
 * \param durations
 */
void Facade::drawPlots(vector<Point> bytesUsed, vector<Point> durations){
    QVector<double> number;
    QVector<double> time;
    QVector<double> memory;
    for (unsigned int i=0; i<bytesUsed.size(); i++){
        number.push_back(bytesUsed[i].x);
        memory.push_back(bytesUsed[i].y);
        time.push_back(durations[i].y);
        QString s = QString::number(number[i])+" elements: "+QString::number(memory[i])+" bytes used, "+QString::number(time[i])+" seconds;";
        info->append(s);
    }
    // adding data to plots
    clearPlot(plot_time);
    clearPlot(plot_memo);
    addPlot(plot_time, number, time);
    addPlot(plot_memo, number, memory);

    double currentX = number.front();
    double approxStep = (number.back() - number.front()) / accuracy;

    QVector<double> approxNumPoints;
    QVector<double> approxTimePoints;
    QVector<double> approxMemPoints;
    for(int i = 0; i < accuracy; i++) {
        approxNumPoints.push_back(currentX);
        approxTimePoints.push_back(timeFunc->getPoint(currentX).y);
        approxMemPoints.push_back(memoryFunc->getPoint(currentX).y);
        currentX += approxStep;
    }
    // adding aproximation to plots
    addAproximationPlot(plot_memo, approxNumPoints, approxMemPoints);
    addAproximationPlot(plot_time, approxNumPoints, approxTimePoints);
}
