//
// Created by zaxx4 on 03.05.2024.
//

#include "Admin.h"

Admin::Admin(const string& email, const string& password,
             const string& name, const string& lastName,
             const string& position, const string& abbreviation,
             const string& phoneNumber, const string& address,
             const string& remarks, double salary, const string& birthDate, EmployeeRepository *employeeRepo)
        : Employee(email, password, name, lastName, position, abbreviation, phoneNumber, address, remarks, salary, birthDate),
                   employeeRepository((EmployeeRepository *)(employeeRepo)) {

}

void Admin::viewEmployeeSalary(Employee &employee) {
    employeeRepository->viewSalary(employee);
}

void Admin::adjustEmployeeSalary(Employee &employee, double newSalary) {
    employeeRepository->adjustSalary(employee, newSalary);
}

void Admin::assignEmployeeAdminRights(Employee &employee) {
    employeeRepository->assignAdminRights(employee);
}

void Admin::removeEmployeeAdminRights(Admin &admin) {
    employeeRepository->removeAdminRights(admin);
}

void Admin::resetEmployeePassword(Employee &employee, string newPassword) {
    employeeRepository->resetPassword(employee, newPassword);
}

const string &Admin::getRemarks() const {
    return Employee::getRemarks();
}

void Admin::setRemarks(const string &remarks) {
    Employee::setRemarks(remarks);
}

const string &Admin::getAddress() const {
    return Employee::getAddress();
}

void Admin::setAddress(const string &address) {
    Employee::setAddress(address);
}

const string &Admin::getPhoneNumber() const {
    return Employee::getPhoneNumber();
}

void Admin::setPhoneNumber(const string &phoneNumber) {
    Employee::setPhoneNumber(phoneNumber);
}

const string &Admin::getAbbreviation() const {
    return Employee::getAbbreviation();
}

void Admin::setAbbreviation(const string &abbreviation) {
    Employee::setAbbreviation(abbreviation);
}

const string &Admin::getPosition() const {
    return Employee::getPosition();
}

void Admin::setPosition(const string &position) {
    Employee::setPosition(position);
}

void Admin::setName(const string &name) {
    Employee::setName(name);
}

const string &Admin::getName() const {
    return Employee::getName();
}

const string &Admin::getLastName() const {
    return Employee::getLastName();
}

void Admin::setLastName(const string &lastName) {
    Employee::setLastName(lastName);
}

double Admin::getSalary() const {
    return Employee::getSalary();
}

void Admin::setSalary(double salary) {
    Employee::setSalary(salary);
}

const string &Admin::getEmail() const {
    return User::getEmail();
}

void Admin::setEmail(const string &email) {
    User::setEmail(email);
}

const string &Admin::getPassword() const {
    return User::getPassword();
}

void Admin::setPassword(const string &password) {
    User::setPassword(password);
}

const string &Admin::getBirthDate() const {
    return Employee::getBirthDate();
}
void Admin::setBirthDate(const string &birthDate) {
    Employee::setBirthDate(birthDate);
}



