#ifndef CARSHARING_712_1_CARREPOSITORY_H
#define CARSHARING_712_1_CARREPOSITORY_H

#include <vector>
#include "../Domain-Car/Car.h"

using namespace std;

class CarRepository {
private:
    vector<Car> cars;

public:
    void addCar(const Car& car);
    void updateCar(const string& licensePlate, const Car& newCarData);
    void removeCar(const string& licensePlate);
    void deactivateCar(const string& licensePlate);
    vector<Car> returnList();
};

#endif //CARSHARING_712_1_CARREPOSITORY_H
