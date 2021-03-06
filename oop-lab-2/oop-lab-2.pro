QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    Approximation/ConstantApproximator.cpp \
    Approximation/Functions/ConstantFunction.cpp \
    facade.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    Approximation/Approximator.cpp \
    Approximation/Functions/Function.cpp \
    Approximation/Functions/LinearFunction.cpp \
    Approximation/Functions/LogarithmicFunction.cpp \
    Approximation/Functions/QuadraticFunction.cpp \
    Approximation/Functions/XLogXFunction.cpp \
    Approximation/LinearApproximator.cpp \
    Approximation/LogarithmicApproximator.cpp \
    Approximation/XLogXApproximator.cpp \
    Approximation/QuadraticApproximator.cpp \
    Diagnostics/MemoryTracker.cpp \
    Diagnostics/MemoryTrackerHook.cpp \
    Diagnostics/TestBuilder.cpp \
    Diagnostics/TimeTrackerHook.cpp



HEADERS += mainwindow.h \
    Approximation/ConstantApproximator.h \
    Approximation/Functions/ConstantFunction.h \
    facade.h \
    qcustomplot.h \
    Approximation/Functions/Function.h \
    Approximation/Functions/LinearFunction.h \
    Approximation/Functions/LogarithmicFunction.h \
    Approximation/Functions/QuadraticFunction.h \
    Approximation/Functions/XLogXFunction.h \
    Diagnostics/DataGenerator.h \
    Diagnostics/MemoryTracker.h \
    Diagnostics/MemoryTrackerHook.h \
    Diagnostics/Random.h \
    Diagnostics/TestBuilder.h \
    Diagnostics/TimeTrackerHook.h \
    Approximation/ApproximationData.h \
    Approximation/Approximator.h \
    Approximation/LinearApproximator.h \
    Approximation/LogarithmicApproximator.h \
    Approximation/XLogXApproximator.h \
    Approximation/Point.h \
    Approximation/QuadraticApproximator.h \
    SortingAlgorithms/GappingStrategy.h \
    SortingAlgorithms/PivotingStrategy.h \
    SortingAlgorithms/SortingAlgorithms.h

FORMS += mainwindow.ui

INCLUDEPATH += ./Armadillo/include

win64{
    LIBS += -L"$$PWD/Armadillo/examples/lib_win64" -llapack_win64_MT -lblas_win64_MT
}
win32{
    LIBS += -L"$$PWD/Armadillo/examples/lib_win64" -llapack_win64_MT -lblas_win64_MT
}
unix{
    LIBS += -L"$$PWD/Armadillo/include" -llapack -lopenblas
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Approximation/README \
    SortingAlgorithms/README.md

RESOURCES += \
    img.qrc


