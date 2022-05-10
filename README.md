# Visualization of population dynamics during the pandemic 
based on [SIRD model](https://en.wikipedia.org/wiki/Compartmental_models_in_epidemiology#The_SIRD_model)

## Technology
GUI created in C++ with Qt library. [QCustomPlot](https://www.qcustomplot.com/index.php/introduction) was used to generate plots.

## Solved ODE system
![equation](https://latex.codecogs.com/svg.image?%5Cfrac%7B%5Cpartial%20S%7D%7B%5Cpartial%20t%7D%20=%20-%5Cfrac%7B%5Cbeta%20I%20S%7D%7BN%7D%20) <br>
![equation](https://latex.codecogs.com/svg.image?%5Cfrac%7B%5Cpartial%20I%7D%7B%5Cpartial%20t%7D%20=%20%5Cfrac%7B%5Cbeta%20I%20S%7D%7BN%7D%20-%20%5Cgamma%20I%20-%20%5Cmu%20I) <br>
![equation](https://latex.codecogs.com/svg.image?%5Cfrac%7B%5Cpartial%20R%7D%7B%5Cpartial%20t%7D%20=%20%5Cgamma%20I) <br>
![equation](https://latex.codecogs.com/svg.image?%5Cfrac%7B%5Cpartial%20D%7D%7B%5Cpartial%20t%7D%20=%20%5Cmu%20I) <br>

where : <br>
S - healthy population susceptible to infection <br>
I - infected population <br>
R - a recovered, resistant population <br>
D - dead population <br>
![beta](https://latex.codecogs.com/svg.image?%5Cbeta) - infection rate <br>
![gamma](https://latex.codecogs.com/svg.image?%5Cgamma) - recovery rate <br>
![mu](https://latex.codecogs.com/svg.image?%5Cmu) - mortality rate <br>


### Solving method
First order Runge Kutta [method](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods) (the Euler [method](https://en.wikipedia.org/wiki/Euler_method)) is used to solve the above ODE system

## Result
![gif](result/pandemic_ode_results.gif)
