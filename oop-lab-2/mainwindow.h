#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QDebug"
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include "qcustomplot.h"
#include "facade.h"

#include "Approximation/Point.h"
#include "Approximation/LogarithmicApproximator.h"
#include "Approximation/ApproximationData.h"

#include "Diagnostics/MemoryTracker.h"
#include "Diagnostics/MemoryTrackerHook.h"
#include "Diagnostics/TestBuilder.h"
#include "Diagnostics/DataGenerator.h"
#include "Diagnostics/TimeTrackerHook.h"
#include "SortingAlgorithms/SortingAlgorithms.h"
#include <vector>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_saveButton_clicked();
    void setInfo();
private:
    Ui::MainWindow *ui;
    Facade facade;
};
#endif // MAINWINDOW_H
