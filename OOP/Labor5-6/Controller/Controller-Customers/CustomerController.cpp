//
// Created by Diana on 03-May-2024.
//

#include "CustomerController.h"
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <cstring>

CustomerController::CustomerController(CustomerRepository customerRepo) : customerRepo(std:: move(customerRepo)) {}

void CustomerController::addCustomer(const std::string &id, const std::string &name, const std::string &lastName,
                                     const std::string &email, const std::string &password, const std::string &phoneNumber,
                                     const std::string &address, const std::string &remarks, bool gdprDeleted, bool isEmployee) {


        Customer addedCustomer(id,name,lastName,email,phoneNumber,address,remarks,gdprDeleted,password);
        customerRepo.createCustomer(addedCustomer,isEmployee);

}

void CustomerController::deleteCustomer(const std::string &deleteName, bool isEmployee) {
    vector<Customer> matchingCustomer= findByName(deleteName);
    if (!matchingCustomer.empty())
        for (const Customer &customer: matchingCustomer)
        {
            if (deleteName==customer.getName() || deleteName==customer.getlastName())
                customerRepo.deleteCustomer(customer,isEmployee);
        }

}

void CustomerController::setCustomerOrder(const std::string &name, const std::string &car, Date date, bool isEmployee) {
    vector<Customer> matchingCustomer= findByName(name);
    if (!matchingCustomer.empty())
        for (const Customer &customer: matchingCustomer)
        {
            if (customer.getName()==name || customer.getlastName()==name)
                customerRepo.setOrder(customer,car,date,isEmployee);
        }
}

vector<Customer> CustomerController::getAll() {
    vector <Customer> allCustomers;
    allCustomers=customerRepo.getAll();
    sort(allCustomers.begin(), allCustomers.end(),
         [](const Customer &customer1, const Customer &customer2) { return customer1.getlastName() < customer2.getlastName(); });
    return allCustomers;
}

Customer CustomerController::findByEmail(std::string &email) {
    vector<Customer> foundCustomers;
    for (const Customer &customer: customerRepo.getAll()) {

        if (customer.getEmail() == email)
            foundCustomers.push_back(customer);
    }
    return foundCustomers[0];
}

vector<Customer> CustomerController::findByPhone(std::string &phoneNumber) {
    vector<Customer> foundCustomers;
    for (const Customer &customer: customerRepo.getAll()) {

        if (customer.getPhoneNumber() == phoneNumber)
            foundCustomers.push_back(customer);
    }
    return foundCustomers;
}

vector<Customer> CustomerController::findByName(const std::string &name) {
    vector<Customer> foundCustomers;
    for (const Customer &customer: customerRepo.getAll()) {

        if (customer.getName() == name || customer.getlastName()==name)
            foundCustomers.push_back(customer);
    }
    return foundCustomers;
}

bool CustomerController::compareCarOrderDate(const Customer &customer1, const Customer &customer2) {
    if (customer1.getOrderDate().year != customer2.getOrderDate().year)
        return customer1.getOrderDate().year < customer2.getOrderDate().year;

    if (customer1.getOrderDate().month != customer2.getOrderDate().month)
        return customer1.getOrderDate().month < customer2.getOrderDate().month;

    return customer1.getOrderDate().day < customer2.getOrderDate().day;
}

vector<Customer> CustomerController::findByOrderedCar(std::string &orderedCar) {
    vector<Customer> foundCustomers;
    for (const Customer &customer: customerRepo.getAll()) {

        if (customer.getHasOrderedCar() && customer.getOrderedCar()==orderedCar)
            foundCustomers.push_back(customer);
    }

    sort(foundCustomers.begin(),foundCustomers.end(), compareCarOrderDate);
    return foundCustomers;
}


void CustomerController::changePassword(std::string &email, const std::string &newpassword, const std::string &password) {

    Customer customer=this->findByEmail(email);

    if(customer.getId().empty()){
        throw runtime_error("Customer not found");
    }

    if (!customer.authenticate(email, password)){
        throw runtime_error("Unauthorized access");
    }
    customer.setPassword(newpassword);
    customerRepo.modifyCustomer(customer);

}

void CustomerController::changeRemarks(std::string& email, const std::string& newRemarks, const std::string& password) {

    Customer customer = this->findByEmail(email);

    if (customer.getId().empty()) {
        throw runtime_error("Customer not found");
    }

    if (!customer.authenticate(email,password)) {
        throw runtime_error("Unauthorized access");
    }
    customer.setRemarks(newRemarks);
    customerRepo.modifyCustomer(customer);

}

