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
    facade.addInfoBox(ui->info);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    facade.runSimulation(ui->algorithm->currentIndex(),ui->data_order->currentIndex(),ui->num_elem->value(),ui->step->value(),ui->num_sorts->value());
    setInfo();
}

void MainWindow::setInfo(){
    ui->alg_type->setText(ui->algorithm->currentText());
    ui->data_order_info->setText(ui->data_order->currentText());
    ui->time_func->setText(QString::fromStdString(facade.getTimeFunc()->getName()));
    ui->memory_func->setText(QString::fromStdString(facade.getMemoryFunc()->getName()));
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save information about sorting"), "../saves/"+ui->algorithm->currentText(),
            tr("Text files (*.txt)"));
        if (fileName.isEmpty()) return;
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
        QTextStream out(&file);
        out << "Algorithm: " << ui->alg_type->text()<< "\n";
        out << "Number of elements: "<<facade.getNumberElements()<< "\n";
        out << "Steps: "<<facade.getStep()<< "\n";
        out << "Number of sorts: "<<facade.getNumberSorts()<< "\n";
        out << "Time function: "<<ui->time_func->text()<<"\n";
        out << "Memory function: "<<ui->memory_func->text()<<"\n";
        out << "Additional information: \n";
        out << ui->info->toPlainText();
}
