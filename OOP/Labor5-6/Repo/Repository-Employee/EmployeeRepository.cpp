//
// Created by zaxx4 on 03.05.2024.
//

#include "EmployeeRepository.h"
#include "Admin.h"
#include <algorithm>

void EmployeeRepository::adjustSalary(Employee &employee, double newSalary) {
    for (int i = 0; i < employees_.size(); i++)
        if (employee.getEmail() == employees_[i].getEmail()) {
            employee.setSalary(newSalary);
        }
}

void EmployeeRepository::addAdmin(Admin &admin) {
    admins_.push_back(admin);
}

void EmployeeRepository::removeAdmin(const string &email) {
    admins_.erase(std::remove_if(admins_.begin(), admins_.end(),
                                    [&email](const Admin& e) { return e.getEmail() == email; }), admins_.end());
}

void EmployeeRepository::addEmployee(Employee &employee) {
    employees_.push_back(employee);
}

void EmployeeRepository::removeEmployee(const string &email) {
    employees_.erase(std::remove_if(employees_.begin(), employees_.end(),
                                   [&email](const Employee& e) { return e.getEmail() == email; }), employees_.end());
}

void EmployeeRepository::removeAdminRights(Admin &admin) {
    Employee employee(admin.getEmail(), admin.getPassword(), admin.getName(),
                      admin.getLastName(), admin.getPosition(), admin.getAbbreviation(),
                      admin.getPhoneNumber(), admin.getAddress(), admin.getRemarks(),
                      admin.getSalary(), admin.getBirthDate());
    addEmployee(employee);
    removeAdmin(admin.getEmail());
}

void EmployeeRepository::assignAdminRights(Employee &employee) {
    Admin admin(employee.getEmail(), employee.getPassword(), employee.getName(),
                employee.getLastName(), employee.getPosition(), employee.getAbbreviation(),
                employee.getPhoneNumber(), employee.getAddress(), employee.getRemarks(),
                employee.getSalary(), employee.getBirthDate(), this);
    addAdmin(admin);
    removeEmployee(employee.getEmail());
}

void EmployeeRepository::viewSalary(Employee &employee){
    std::cout << "Salary of " << employee.getName() << ": $" << employee.getSalary() << std::endl;
}

void EmployeeRepository::resetPassword(Employee &employee, string newPassword) {
    employee.setPassword(newPassword);
    std::cout << "Password reset for " << employee.getName() << std::endl;
}

void EmployeeRepository::startData() {}

void EmployeeRepository::setupUnitTests() {}

Employee* EmployeeRepository::searchEmployeeByAbbreviation(const std::string &abbreviation) {
    for (auto& employee : employees_) {
        if (employee.getAbbreviation() == abbreviation) {
            return &employee;
        }
    }
    return nullptr;
}

Employee* EmployeeRepository::searchEmployeeByEmail(const std::string &email) {
    for (auto& employee : employees_) {
        if (employee.getEmail() == email) {
            return &employee;
        }
    }
    return nullptr;
}

// Funcții Adaugate M:


vector<Employee> EmployeeRepository::getAllEmployees() const {
    vector<Employee> sortedEmployees = employees_;
    sort(sortedEmployees.begin(), sortedEmployees.end(), [](const Employee &a, const Employee &b) {
        return a.getName() < b.getName() || (a.getName() == b.getName() && a.getLastName() < b.getLastName());
    });
    return sortedEmployees;
}

vector<Employee> EmployeeRepository::searchEmployeesByNameAndLastName(const string &name, const string &lastName) const {
    vector<Employee> result;
    copy_if(employees_.begin(), employees_.end(), back_inserter(result), [&name, &lastName](const Employee &e) {
        return e.getName() == name && e.getLastName() == lastName;
    });
    return result;
}

vector<Employee> EmployeeRepository::searchEmployeesByBirthDateRange(const string &startDate, const string &endDate) const {
    vector<Employee> result;
    copy_if(employees_.begin(), employees_.end(), back_inserter(result), [&startDate, &endDate](const Employee &e) {
        string birthDate = e.getBirthDate();
        return birthDate >= startDate && birthDate <= endDate;
    });
    return result;
}