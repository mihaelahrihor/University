//
// Created by Dell on 5/20/2024.
//

#include "../Controller-Employee/EmployeeController.h"
#include <iostream>

EmployeeController::EmployeeController(EmployeeRepository &repository) : repository_(repository){}

//Functii adaugate Mihaela:
vector<Employee> EmployeeController::getAllEmployees() const {
    return repository_.getAllEmployees();
}

vector<Employee> EmployeeController::searchEmployeesByNameAndLastName(const string &name, const string &lastName) const {
    return repository_.searchEmployeesByNameAndLastName(name, lastName);
}

vector<Employee> EmployeeController::searchEmployeesByBirthDateRange(const string &startDate, const string &endDate) const {
    return repository_.searchEmployeesByBirthDateRange(startDate, endDate);
}