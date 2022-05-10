#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "sliders.h"
#include "qcustomplot.h"
#include "simulation.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    Sliders sliders;
    QCustomPlot plot;
    Simulation simulation;
    QHBoxLayout layout;
    int endingTime;
    double interval;
    QVector<double> sus, inf, dead, rec, time;

public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

};

#endif // MAINWINDOW_H
