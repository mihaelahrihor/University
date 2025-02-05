
#include "EmployeeUI.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void EmployeeUI::printEmployees(const vector<Employee>& employees) const {
    for (const auto& employee : employees) {
        cout << employee.getName() << " " << employee.getLastName() << ", " << employee.getEmail() << endl;
    }
}

void EmployeeUI::listAllEmployees() const {
    auto employees = controller_.getAllEmployees();
    printEmployees(employees);
}

void EmployeeUI::searchEmployeeByNameAndLastName() const {
    string name, lastName;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter last name: ";
    cin >> lastName;
    auto employees = controller_.searchEmployeesByNameAndLastName(name, lastName);
    printEmployees(employees);
}

void EmployeeUI::searchEmployeeByBirthDateRange() const {
    string startDate, endDate;
    cout << "Enter start date (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter end date (YYYY-MM-DD): ";
    cin >> endDate;
    auto employees = controller_.searchEmployeesByBirthDateRange(startDate, endDate);
    printEmployees(employees);
}
