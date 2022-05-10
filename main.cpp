#include "sliders.h"

#include <QApplication>
#include <QWidget>
#include "qcustomplot.h"
#include <QVector>
#include <QSlider>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.showMaximized();

    return a.exec();
}
