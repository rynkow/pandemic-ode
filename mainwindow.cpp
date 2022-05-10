#include "mainwindow.h"

void setGrephParameters(QCPGraph *graph,  QVector<double> &xData, QVector<double> &yData, QPen pen, const char *name){
    graph->setData(xData,yData);
    graph->setName(name);
    graph->setPen(pen);
}

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), sliders(),
    simulation(2000, 200, 0.5, 0.01, 0.001), plot(), layout(),
    sus(50000), inf(50000), dead(50000), rec(50000), time(50000)

{
    this->setLayout(&this->layout);
    layout.addWidget(&plot);
    layout.addWidget(&sliders);
    endingTime = 500;
    interval = 0.01;
    int size = endingTime/interval;
    for (int i = 0; i < size-1; i++){
        time[i+1] = time[i] + interval;
    }
    simulation.simulate(endingTime, interval, sus, inf, rec, dead);

    plot.addGraph();

    plot.addGraph();

    plot.addGraph();

    plot.addGraph();

    setGrephParameters(plot.graph(0), time, sus, QPen("Blue"), "zdrowi");

    setGrephParameters(plot.graph(1), time, inf, QPen("Red"), "zainfekowani");

    setGrephParameters(plot.graph(2), time, rec, QPen("Green"), "odporni");

    setGrephParameters(plot.graph(3), time, dead, QPen("Black"), "zmarli");


    // give the axes some labels:
    plot.xAxis->setLabel("czas");
    plot.yAxis->setLabel("populacja");
    // set axes ranges, so we see all data:
    plot.xAxis->setRange(0, endingTime);
    plot.yAxis->setRange(0, 3000);
    plot.legend->setVisible(true);
    plot.replot();


    sliders.connect(&sliders, &Sliders::valueChanged, &sliders, [&](){
          simulation.setParameters(
                      sliders.startingHealthyPopulation(),
                      sliders.startingInfectedPopulation(),
                      sliders.infectionRate(),
                      sliders.recoveryRate(),
                      sliders.mortalityRate()
                      );

          simulation.simulate(endingTime, interval, sus, inf, rec, dead);
          plot.yAxis->setRange(0,sliders.startingHealthyPopulation() + sliders.startingInfectedPopulation());
          plot.xAxis->setRange(0, sliders.maxSimulationTime());

          plot.graph(0)->setData(time, sus);
          plot.graph(1)->setData(time, inf);
          plot.graph(2)->setData(time, rec);
          plot.graph(3)->setData(time, dead);
          plot.replot();
    });
}
