//
// Created by andre on 14/05/2024.
//

#ifndef CARSHARING_712_1_CAR_H
#define CARSHARING_712_1_CAR_H

#include <string>

using namespace std;

class Car {
private:
    string licensePlate;
    string model;
    string brand;
    int firstRegistrationYear;
    int mileage;
    double dailyPrice;
    string fuelType;
    string transmission;
    string color;
    string remark;
    bool ordered; 
    bool active;  

public:
    Car(string licensePlate, string model, string brand, int firstRegistrationYear, int mileage, double dailyPrice, string fuelType, string transmission, string color, string remark);

    string getLicensePlate() const;
    string getModel() const;
    string getBrand() const;
    int getFirstRegistrationYear() const;
    int getMileage() const;
    double getDailyPrice() const;
    string getFuelType() const;
    string getTransmission() const;
    string getColor() const;
    string getRemark() const;

    void setLicensePlate(const string &licensePlate);
    void setModel(const string &model);
    void setBrand(const string &brand);
    void setFirstRegistrationYear(int firstRegistrationYear);
    void setMileage(int mileage);
    void setDailyPrice(double dailyPrice);
    void setFuelType(const string &fuelType);
    void setTransmission(const string &transmission);
    void setColor(const string &color);
    void setRemark(const string &remark);
    bool isOrdered() const;
    void setOrdered(bool ordered);
    bool isActive() const;
    void setActive(bool active);
};


#endif //CARSHARING_712_1_CAR_H
