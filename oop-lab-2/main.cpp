#include "mainwindow.h"
#include <vector>

#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Sort");
    w.setWindowIcon(QIcon(":/icon/icon.ico"));
    w.show();

    return a.exec();
}
