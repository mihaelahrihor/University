#include "Car.h"

Car::Car(string licensePlate, string model, string brand, int firstRegistrationYear, int mileage, double dailyPrice, string fuelType, string transmission, string color, string remark)
        : licensePlate(move(licensePlate)), model(move(model)), brand(move(brand)), firstRegistrationYear(firstRegistrationYear), mileage(mileage), dailyPrice(dailyPrice), fuelType(move(fuelType)), transmission(move(transmission)), color(move(color)), remark(move(remark)) {}

string Car::getLicensePlate() const { return licensePlate; }
string Car::getModel() const { return model; }
string Car::getBrand() const { return brand; }
int Car::getFirstRegistrationYear() const { return firstRegistrationYear; }
int Car::getMileage() const { return mileage; }
double Car::getDailyPrice() const { return dailyPrice; }
string Car::getFuelType() const { return fuelType; }
string Car::getTransmission() const { return transmission; }
string Car::getColor() const { return color; }
string Car::getRemark() const { return remark; }

void Car::setLicensePlate(const string &licensePlate) { this->licensePlate = licensePlate; }
void Car::setModel(const string &model) { this->model = model; }
void Car::setBrand(const string &brand) { this->brand = brand; }
void Car::setFirstRegistrationYear(int firstRegistrationYear) { this->firstRegistrationYear = firstRegistrationYear; }
void Car::setMileage(int mileage) { this->mileage = mileage; }
void Car::setDailyPrice(double dailyPrice) { this->dailyPrice = dailyPrice; }
void Car::setFuelType(const string &fuelType) { this->fuelType = fuelType; }
void Car::setTransmission(const string &transmission) { this->transmission = transmission; }
void Car::setColor(const string &color) { this->color = color; }
void Car::setRemark(const string &remark) { this->remark = remark;}
bool Car::isOrdered() const {return ordered;}
void Car::setOrdered(bool ordered) {this->ordered = ordered;}
bool Car::isActive() const {return active;}
void Car::setActive(bool active) {this->active = active;}