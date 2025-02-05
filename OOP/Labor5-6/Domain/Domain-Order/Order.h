#ifndef CARSHARING_712_1_ORDER_H
#define CARSHARING_712_1_ORDER_H

#include <iostream>
#include "string"
#include "../Domain-Customer/Customer.h"
#include "../Domain-Employee/Employee.h"
#include "../Domain-Car/Car.h"

using namespace std;

enum class Status {
    Reservation,
    Order,
    Completed
};

class Order {
private:
    string orderNumber;
    Date orderDate;
    Status status;
    Car orderedCar;
    Date begin;
    Date end;
    Customer customer;
    Employee employee;
    int totalSum;
    string remarks;

public:
    Order(const string &orderNumber, const Date &orderDate, Status status, const Car &orderedCar,
          const Date &begin, const Date &end, const Customer &customer, const Employee &employee,
          int totalSum, const string &remarks);

    string getOrderNumber() const;

    void setOrderNumber(const string &orderNumber);

    Date getOrderDate() const;

    void setOrderDate(const Date &orderDate);

    Status getStatus() const;

    void setStatus(Status status);

    Car getOrderedCar() const;

    void setOrderedCar(const Car &orderedCar);

    Date getBegin() const;

    void setBegin(const Date &begin);

    Date getEnd() const;

    void setEnd(const Date &end);

    Customer getCustomer() const;

    void setCustomer(const Customer &customer);

    Employee getEmployee() const;

    void setEmployee(const Employee &employee);

    int getTotalSum() const;

    void setTotalSum(int totalSum);

    string getRemarks() const;

    void setRemarks(const string &remarks);

    static string statusToString(Status stat);

    void printDetails() const;
};

#endif //CARSHARING_712_1_ORDER_H
