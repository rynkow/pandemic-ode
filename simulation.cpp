#include "simulation.h"


Simulation::Simulation(int staringHealthyPopulation, int startingInfectedPopulation, double infectionRate, double recoveryRate, double mortalityRate)
{
    this->infectionRate = infectionRate;
    this->mortalityRate = mortalityRate;
    this->recoveryRate = recoveryRate;
    this->staringHealthyPopulation = staringHealthyPopulation;
    this->startingInfectedPopulation = startingInfectedPopulation;
}

void Simulation::setParameters(int staringHealthyPopulation, int startingInfectedPopulation, double infectionRate, double recoveryRate, double mortalityRate)
{
    this->infectionRate = infectionRate;
    this->mortalityRate = mortalityRate;
    this->recoveryRate = recoveryRate;
    this->staringHealthyPopulation = staringHealthyPopulation;
    this->startingInfectedPopulation = startingInfectedPopulation;
}


void Simulation::simulate(int endingTime, float interval, QVector<double> &suspectible, QVector<double> &infected, QVector<double> &recovered, QVector<double> &dead)
{
    int size = (int)endingTime/interval;
    printf("size: %d\n", size);
    infected[0] = startingInfectedPopulation;
    suspectible[0] = staringHealthyPopulation;
    recovered[0] = 0;
    dead[0] = 0;
    int population = staringHealthyPopulation + startingInfectedPopulation;

    int i;
    for (i = 0; i < size-1; i++){
        suspectible[i+1] =suspectible[i] + interval*((-1)*infectionRate*infected[i]*suspectible[i]/population);
        infected[i+1] =infected[i] + interval*((infectionRate*infected[i]*suspectible[i]/population) - recoveryRate*infected[i] - mortalityRate*infected[i]);
        dead[i+1] = dead[i] + interval*mortalityRate*infected[i];
        recovered[i+1] = recovered[i] + interval*recoveryRate*infected[i];
    }
    printf("%d\n", i);

    return;
}
