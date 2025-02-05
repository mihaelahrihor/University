//
// Created by Dell on 5/20/2024.
//

#ifndef CARSHARING_712_1_EMPLOYEECONTROLLER_H
#define CARSHARING_712_1_EMPLOYEECONTROLLER_H

#include "../Repository-Employee/EmployeeRepository.h"
#include "../Domain-Employee/Employee.h"

class EmployeeController{

private:
    EmployeeRepository repository_;

public:

    EmployeeController(EmployeeRepository &repository);

    void adjustSalary(Employee &employee, double newSalary) {
        repository_.adjustSalary(employee, newSalary);
    }

    void addAdmin(Admin &admin) {
        repository_.addAdmin(admin);
    }

    void removeAdmin(const std::string &email) {
        repository_.removeAdmin(email);
    }

    void addEmployee(Employee &employee) {
        repository_.addEmployee(employee);
    }

    void removeEmployee(const std::string &email) {
        repository_.removeEmployee(email);
    }

    void removeAdminRights(Admin &admin) {
        repository_.removeAdminRights(admin);
    }

    void assignAdminRights(Employee &employee) {
        repository_.assignAdminRights(employee);
    }

    void viewSalary(Employee &employee) {
        repository_.viewSalary(employee);
    }

    void resetPassword(Employee &employee, std::string newPassword) {
        repository_.resetPassword(employee, newPassword);
    }

    Employee* searchEmployeeByAbbreviation(const std::string &abbreviation) {
        return repository_.searchEmployeeByAbbreviation(abbreviation);
    }

    Employee* searchEmployeeByEmail(const std::string &email) {
        return repository_.searchEmployeeByEmail(email);
    }

    void startData() {
        repository_.startData();
    }

    void setupUnitTests() {
        repository_.setupUnitTests();
    }

    //Functii adaugate Mihaela
    vector<Employee> getAllEmployees() const;

    vector<Employee> searchEmployeesByNameAndLastName(const string &name, const string &lastName) const;

    vector<Employee> searchEmployeesByBirthDateRange(const string &startDate, const string &endDate) const;
};

#endif //CARSHARING_712_1_EMPLOYEECONTROLLER_H
