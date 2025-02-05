//
// Created by zaxx4 on 03.05.2024.
//

#ifndef CARSHARING_712_1_ADMIN_H
#define CARSHARING_712_1_ADMIN_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "../Domain-Employee/Employee.h"
#include "../Repository-Employee/EmployeeRepository.h"
class EmployeeRepository;

using namespace std;

class Admin : public Employee{

private:

    EmployeeRepository *employeeRepository;

public:
    Admin(const string &email, const string &password, const string &name, const string &lastName,
          const string &position, const string &abbreviation, const string &phoneNumber, const string &address,
          const string &remarks, double salary, const string &birthDate, EmployeeRepository *employeeRepo);


    void viewEmployeeSalary(Employee &employee);
    void adjustEmployeeSalary(Employee &employee, double newSalary);
    void assignEmployeeAdminRights(Employee &employee);
    void removeEmployeeAdminRights(Admin &admin);
    void resetEmployeePassword(Employee &employee, string newPassword);

    const string &getRemarks() const override;

    void setRemarks(const string &remarks) override;

    const string &getAddress() const override;

    void setAddress(const string &address) override;

    const string &getPhoneNumber() const override;

    void setPhoneNumber(const string &phoneNumber) override;

    const string &getAbbreviation() const override;

    void setAbbreviation(const string &abbreviation) override;

    const string &getPosition() const override;

    void setPosition(const string &position) override;

    void setName(const string &name) override;

    const string &getName() const override;

    const string &getLastName() const override;

    void setLastName(const string &lastName) override;

    double getSalary() const override;

    void setSalary(double salary) override;

    const string &getEmail() const override;

    void setEmail(const string &email) override;

    const string &getPassword() const override;

    void setPassword(const string &password) override;

    const string &getBirthDate() const override;

    void setBirthDate(const string &birthDate) override;

};

#endif //CARSHARING_712_1_ADMIN_H
