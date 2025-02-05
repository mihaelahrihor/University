//
// Created by zaxx4 on 03.05.2024.
//

#ifndef CARSHARING_712_1_EMPLOYEE_H
#define CARSHARING_712_1_EMPLOYEE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "../Domain-User/User.h"
class User;

using namespace std;

class Employee : public User {

protected:

    string name_;
    string lastName_;
    string position_;
    string abbreviation_;
    string phoneNumber_;
    string address_;
    string remarks_;
    double salary_;
    string birthDate_;//Adaugat M


public:

    Employee(const string& email, const string& password,
             const string& name, const string& lastName,
             const string& position, const string& abbreviation,
             const string& phoneNumber, const string& address,
             const string& remarks, double salary, const string& birthDate)
            : User(email, password), name_(name), lastName_(lastName), position_(position),
              abbreviation_(abbreviation), phoneNumber_(phoneNumber), address_(address),
              remarks_(remarks), salary_(salary), birthDate_(birthDate){}

    virtual const string &getRemarks() const;

    virtual void setRemarks(const string &remarks);

    virtual const string &getAddress() const;

    virtual void setAddress(const string &address);

    virtual const string &getPhoneNumber() const;

    virtual void setPhoneNumber(const string &phoneNumber);

    virtual const string &getAbbreviation() const;

    virtual void setAbbreviation(const string &abbreviation);

    virtual const string &getPosition() const;

    virtual void setPosition(const string &position);

    virtual void setName(const string &name);

    virtual const string &getName() const;

    virtual const string &getLastName() const;

    virtual void setLastName(const string &lastName);

    virtual double getSalary() const;

    virtual void setSalary(double salary);

    virtual const string &getBirthDate() const;

    virtual void setBirthDate(const string &birthDate);

};

#endif //CARSHARING_712_1_EMPLOYEE_H
