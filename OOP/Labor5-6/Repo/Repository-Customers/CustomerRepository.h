//
// Created by Vanessa on 02.05.2024.
//

#ifndef CARSHARING_712_1_CUSTOMERREPOSITORY_H
#define CARSHARING_712_1_CUSTOMERREPOSITORY_H

#include <vector>
#include <stdexcept>
#include "../Domain-Customer/Customer.h"
#include "../Repository-Employee/EmployeeRepository.h"

using namespace std;

class CustomerRepository {
private:
    vector<Customer> customers_;

    void startData();

public:
    CustomerRepository();
    void createCustomer(const Customer& customer, bool isEmployee);
    void modifyCustomer(const Customer& customer);
    void deleteCustomer(const Customer& customer, bool isEmployee);
    void anonymizeCustomer(const Customer& customer, bool isEmployee);
    void setOrder(const Customer& customer, const string car, Date date, bool isEmployee);
    vector<Customer> getAll();
};


#endif //CARSHARING_712_1_CUSTOMERREPOSITORY_H
