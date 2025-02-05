#ifndef CONTROLLER_AUTOS_CONTROLLER_H
#define CONTROLLER_AUTOS_CONTROLLER_H

#include <iostream>
#include <string>
#include "../Repository-Car/CarRepository.h"

using namespace std;

class Control {
private:
    vector<Car> cars;
    CarRepository repo;
public:
    Control();
    bool PlateCheck();
    bool PlateLettersCheck();
    bool YearCheck();
    bool KmPriceCheck();
};

#endif //CONTROLLER_AUTOS_CONTROLLER_H
