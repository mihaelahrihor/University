#include "CarRepository.h"
#include <algorithm>
#include <stdexcept>

void CarRepository::addCar(const Car& car) {
    cars.push_back(car);
}

void CarRepository::updateCar(const string& licensePlate, const Car& newCarData) {
    for (Car& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            car = newCarData;
            return;
        }
    }
    throw runtime_error("Car not found");
}

void CarRepository::removeCar(const string& licensePlate) {
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->getLicensePlate() == licensePlate) {
            if (it->isOrdered()) {
                throw runtime_error("Car cannot be deleted because it has been ordered before");
            }
            cars.erase(it);
            return;
        }
    }
    throw runtime_error("Car not found");
}

void CarRepository::deactivateCar(const string& licensePlate) {
    for (Car& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            if (car.isOrdered()) {
                throw runtime_error("Car cannot be deactivated because it is currently ordered");
            }
            car.setActive(false);
            return;
        }
    }
    throw runtime_error("Car not found");
}


vector<Car> CarRepository::returnList() {
    return cars;
}

