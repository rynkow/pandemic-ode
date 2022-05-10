#ifndef SLIDERS_H
#define SLIDERS_H

#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>

#include "simulation.h"

class Sliders : public QWidget
{
    Q_OBJECT

private:
    QSlider startingHealthyPopulationSlider;
    QSlider startingInfectedPopulationSlider;
    QSlider infectionRateSlider;
    QSlider recoveryRateSlider;
    QSlider mortalityRateSlider;
    QSlider maxSimulationTimeSlider;

    QLabel startingHealthyPopulationLabel;
    QLabel startingInfectedPopulationLabel;
    QLabel infectionRateLabel;
    QLabel recoveryRateLabel;
    QLabel mortalityRateLabel;
    QLabel maxSimulationTimeLabel;

    QVBoxLayout layout;


public:
    Sliders(QWidget *parent = nullptr);
    ~Sliders();

    int startingHealthyPopulation(){
        return startingHealthyPopulationSlider.value();
    }

    int startingInfectedPopulation(){
        return startingInfectedPopulationSlider.value();
    }
    double infectionRate(){
        return infectionRateSlider.value()/1000.0;
    }
    double recoveryRate(){
        return recoveryRateSlider.value()/10000.0;
    }
    double mortalityRate(){
        return mortalityRateSlider.value()/10000.0;
    }

    int maxSimulationTime(){
        return maxSimulationTimeSlider.value();
    }

signals:
    void valueChanged();
};
#endif // SLIDERS_H
