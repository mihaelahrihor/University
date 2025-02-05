//
// Created by zaxx4 on 03.05.2024.
//

#include "Employee.h"

const string &Employee::getName() const {
    return name_;
}

void Employee::setName(const string &name) {
    name_ = name;
}


const string &Employee::getLastName() const {
    return lastName_;
}

void Employee::setLastName(const string &lastName) {
    lastName_ = lastName;
}

const string &Employee::getPosition() const {
    return position_;
}

void Employee::setPosition(const string &position) {
    position_ = position;
}

const string &Employee::getAbbreviation() const {
    return abbreviation_;
}

void Employee::setAbbreviation(const string &abbreviation) {
    abbreviation_ = abbreviation;
}

const string &Employee::getPhoneNumber() const {
    return phoneNumber_;
}

void Employee::setPhoneNumber(const string &phoneNumber) {
    phoneNumber_ = phoneNumber;
}

const string &Employee::getAddress() const {
    return address_;
}

void Employee::setAddress(const string &address) {
    address_ = address;
}

const string &Employee::getRemarks() const {
    return remarks_;
}

void Employee::setRemarks(const string &remarks) {
    remarks_ = remarks;
}

double Employee::getSalary() const {
    return salary_;
}

void Employee::setSalary(double salary) {
    salary_ = salary;
}

//Functii adaugate M:
const string &Employee::getBirthDate() const {
    return birthDate_;
}

void Employee::setBirthDate(const string &birthDate) {
    birthDate_ = birthDate;
}
