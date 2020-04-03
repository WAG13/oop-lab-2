/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QCustomPlot *plot_numb_time;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QCustomPlot *plot_time_memo;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_10;
    QTextEdit *textEdit;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QSpinBox *num_elem;
    QLabel *label_3;
    QSpinBox *step;
    QLabel *label_4;
    QSpinBox *num_sorts;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1166, 621);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 12pt \"Segoe UI\";\n"
"	color: rgb(240, 240, 240);\n"
"	background-color: rgb(90, 80, 80)\n"
"}\n"
"QPushButton{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 166, 0, 255), stop:1 rgba(255, 85, 0, 255));\n"
"border-radius:15px;\n"
"font-whigth:bold;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 200, 96, 255), stop:1 rgba(255, 128, 65, 255));\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 166, 0, 240), stop:1 rgba(255, 85, 0, 240));\n"
"}\n"
"\n"
"QSpinBox {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 166, 0, 50), stop:1 rgba(255, 85, 0, 150));\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"	background-color: qlineargradient(spread:pad, x1:0.507, y1:0, x2:0.532, y2:1, stop:0 rgba(255, 166, 0, 255), stop:1 rgba(255, 123, 0, 255));\n"
"}\n"
"QSpinBox::down-button {\n"
""
                        "	background-color: qlineargradient(spread:pad, x1:0.507, y1:0, x2:0.532, y2:1, stop:0 rgba(255, 123, 0, 255), stop:1 rgba(255, 85, 0, 255));\n"
"}\n"
"\n"
"QSpinBox::up-button:hover, QSpinBox::down-button:hover {\n"
"    \n"
"	background-color: rgb(255, 170, 85);\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed,QSpinBox::down-button:pressed {\n"
"    \n"
"	background-color: rgb(200, 100, 0);\n"
"}\n"
"/*\n"
"QSpinBox::up-arrow:disabled, QSpinBox::up-arrow:off, \n"
"QSpinBox::down-arrow:disabled, QSpinBox::down-arrow:off{\n"
"	background-color: rgb(150, 134, 134);\n"
"}*/\n"
"\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid rgb(255, 108, 0);\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"\n"
"QTabBar::tab {\n"
"	color: rgb(39, 39, 39);\n"
"    background: qlineargradient(spread:pad, x1:0.531925, y1:0.807, x2:0.523, y2:0, stop:0 rg"
                        "ba(187, 187, 187, 255), stop:1 rgba(232, 232, 232, 255));\n"
"    \n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    padding: 2px 15px;\n"
"	border:1px solid rgb(90, 80, 80);\n"
"	border-bottom-color: rgb(255, 108, 0); /* same as the pane color */\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	color: rgb(240, 240, 240);\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 166, 0, 255), stop:1 rgba(255, 85, 0, 255))\n"
"}\n"
"QTabBar::tab:hover {\n"
"	color: rgb(240, 240, 240);\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 200, 96, 255), stop:1 rgba(255, 128, 65, 255));\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 30));

        verticalLayout_5->addWidget(label_6);

        plot_numb_time = new QCustomPlot(tab);
        plot_numb_time->setObjectName(QString::fromUtf8("plot_numb_time"));

        verticalLayout_5->addWidget(plot_numb_time);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_6 = new QVBoxLayout(tab_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 30));

        verticalLayout_6->addWidget(label_7);

        plot_time_memo = new QCustomPlot(tab_2);
        plot_time_memo->setObjectName(QString::fromUtf8("plot_time_memo"));

        verticalLayout_6->addWidget(plot_time_memo);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_7 = new QVBoxLayout(tab_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_3->addWidget(label_9);

        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);


        verticalLayout_7->addLayout(horizontalLayout_3);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_7->addWidget(label_10);

        textEdit = new QTextEdit(tab_3);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_7->addWidget(textEdit);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_3->addWidget(tabWidget);


        horizontalLayout->addLayout(verticalLayout_3);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"margin-bottom:10px;"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(191, 0));
        comboBox->setMaximumSize(QSize(360, 16777215));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	color: rgb(39, 39, 39);\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: white;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                                stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"	\n"
"	background-color:qlinear"
                        "gradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 166, 0, 255), stop:1 rgba(255, 85, 0, 255));\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::drop-down:hover {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 200, 96, 255), stop:1 rgba(255, 128, 65, 255));\n"
"}\n"
""));
        comboBox->setMaxVisibleItems(11);

        verticalLayout_4->addWidget(comboBox);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        num_elem = new QSpinBox(centralwidget);
        num_elem->setObjectName(QString::fromUtf8("num_elem"));
        num_elem->setMinimumSize(QSize(0, 0));
        num_elem->setMaximumSize(QSize(180, 16777215));
        num_elem->setMaximum(1000000000);
        num_elem->setValue(100);

        verticalLayout_4->addWidget(num_elem);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        step = new QSpinBox(centralwidget);
        step->setObjectName(QString::fromUtf8("step"));
        step->setMaximumSize(QSize(180, 16777215));
        step->setMaximum(1000000000);
        step->setValue(50);

        verticalLayout_4->addWidget(step);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        num_sorts = new QSpinBox(centralwidget);
        num_sorts->setObjectName(QString::fromUtf8("num_sorts"));
        num_sorts->setMaximumSize(QSize(180, 16777215));
        num_sorts->setReadOnly(false);
        num_sorts->setProperty("showGroupSeparator", QVariant(false));
        num_sorts->setMaximum(1000000000);
        num_sorts->setStepType(QAbstractSpinBox::DefaultStepType);
        num_sorts->setValue(3);

        verticalLayout_4->addWidget(num_sorts);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(200, 40));
        pushButton->setMaximumSize(QSize(200, 16777215));
        pushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(pushButton, 0, Qt::AlignHCenter);


        horizontalLayout->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "some info here", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Plot (number/time)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "blah blah blah", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Plot (time/memory)", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Complexity:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "info:", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "info", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sorting kinds", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Bubble Sort", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Selection Sort", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Insertion Sort", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Quick Sort (Middle pivot)", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Quick Sort (Random pivot)", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Quick Sort (Median of Three pivot) ", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Merge Sort", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Shell Sort (Shell gap)", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "Shell Sort (Hibbard gap)", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "Shell Sort (Sedgewick gap)", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "Shell Sort (Ciura gap)", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Number of elements", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Number of sorts", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
