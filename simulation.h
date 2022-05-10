#ifndef SIMULATION_H
#define SIMULATION_H

#include <QVector>

class Simulation
{
private:
    int staringHealthyPopulation;
    int startingInfectedPopulation;
    double mortalityRate;
    double recoveryRate;
    double infectionRate;



public:
    Simulation(int staringHealthyPopulation, int startingInfectedPopulation, double infectionRate, double recoveryRate, double mortalityRate);

    void setParameters(int staringHealthyPopulation, int startingInfectedPopulation, double infectionRate, double recoveryRate, double mortalityRate);

    void simulate(int endingTime, float interval, QVector<double> &suspectible, QVector<double> &infected, QVector<double> &recovered, QVector<double> &dead);

};

#endif // SIMULATION_H
