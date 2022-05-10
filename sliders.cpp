#include "sliders.h"
#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <iostream>


Sliders::Sliders(QWidget *parent)
    : QWidget(parent), infectionRateSlider(Qt::Horizontal), mortalityRateSlider(Qt::Horizontal), maxSimulationTimeSlider(Qt::Horizontal),
      recoveryRateSlider(Qt::Horizontal), startingHealthyPopulationSlider(Qt::Horizontal), startingInfectedPopulationSlider(Qt::Horizontal)
{
    this->setMaximumWidth(300);

    infectionRateSlider.setMaximum(1000);
    infectionRateSlider.setMinimum(0);
    infectionRateSlider.setValue(500);

    infectionRateLabel.setText("Współczynnik infekcji\n0-1");

    mortalityRateSlider.setMaximum(1000);
    mortalityRateSlider.setMinimum(0);
    mortalityRateSlider.setValue(10);

    mortalityRateLabel.setText("Współczynnik śmiertelności\n0-0.1");


    recoveryRateSlider.setMaximum(1000);
    recoveryRateSlider.setMinimum(0);
    recoveryRateSlider.setValue(100);

    recoveryRateLabel.setText("Współczynnik ozdrowień\n0-0.1");

    startingHealthyPopulationSlider.setMaximum(5000);
    startingHealthyPopulationSlider.setMinimum(0);
    startingHealthyPopulationSlider.setValue(2000);

    startingHealthyPopulationLabel.setText("Początkowa zdrowa populacja\n0-5000");


    startingInfectedPopulationSlider.setMaximum(5000);
    startingInfectedPopulationSlider.setMinimum(0);
    startingInfectedPopulationSlider.setValue(100);

    startingInfectedPopulationLabel.setText("Początkowa zainfekowana populacja\n0-5000");


    maxSimulationTimeSlider.setMaximum(500);
    maxSimulationTimeSlider.setMinimum(0);
    maxSimulationTimeSlider.setValue(500);

    maxSimulationTimeLabel.setText("Końcowy czas symulacji\n0-500");


    layout.addWidget(&infectionRateLabel);
    layout.addWidget(&infectionRateSlider);
    layout.addWidget(&recoveryRateLabel);
    layout.addWidget(&recoveryRateSlider);
    layout.addWidget(&mortalityRateLabel);
    layout.addWidget(&mortalityRateSlider);
    layout.addWidget(&startingHealthyPopulationLabel);
    layout.addWidget(&startingHealthyPopulationSlider);
    layout.addWidget(&startingInfectedPopulationLabel);
    layout.addWidget(&startingInfectedPopulationSlider);
    layout.addWidget(&maxSimulationTimeLabel);
    layout.addWidget(&maxSimulationTimeSlider);

    layout.addStretch(0);
    layout.setSpacing(15);

    setLayout(&layout);


    connect(&infectionRateSlider, &QSlider::valueChanged, this, [=](){emit this->valueChanged();});
    connect(&mortalityRateSlider, &QSlider::valueChanged, this, [=](){emit this->valueChanged();});
    connect(&recoveryRateSlider, &QSlider::valueChanged, this, [=](){emit this->valueChanged();});
    connect(&startingHealthyPopulationSlider, &QSlider::valueChanged, this, [=](){emit this->valueChanged();});
    connect(&startingInfectedPopulationSlider, &QSlider::valueChanged, this, [=](){emit this->valueChanged();});
    connect(&maxSimulationTimeSlider, &QSlider::valueChanged, this, [=](){emit this->valueChanged();});


}

Sliders::~Sliders()
{
}


