#include "Order.h"

Order::Order(const string &orderNumber, const Date &orderDate, Status status, const Car &orderedCar,
             const Date &begin, const Date &end, const Customer &customer, const Employee &employee,
             int totalSum, const string &remarks)
        : orderNumber(orderNumber), orderDate(orderDate), status(status), orderedCar(orderedCar),
          begin(begin), end(end), customer(customer), employee(employee), totalSum(totalSum), remarks(remarks) {}

string Order::getOrderNumber() const { return orderNumber; }

void Order::setOrderNumber(const string &orderNumber) { this->orderNumber = orderNumber; }

Date Order::getOrderDate() const { return orderDate; }

void Order::setOrderDate(const Date &orderDate) { this->orderDate = orderDate; }

Status Order::getStatus() const { return status; }

void Order::setStatus(Status status) { this->status = status; }

Car Order::getOrderedCar() const { return orderedCar; }

void Order::setOrderedCar(const Car &orderedCar) { this->orderedCar = orderedCar; }

Date Order::getBegin() const { return begin; }

void Order::setBegin(const Date &begin) { this->begin = begin; }

Date Order::getEnd() const { return end; }

void Order::setEnd(const Date &end) { this->end = end; }

Customer Order::getCustomer() const { return customer; }

void Order::setCustomer(const Customer &customer) { this->customer = customer; }

Employee Order::getEmployee() const { return employee; }

void Order::setEmployee(const Employee &employee) { this->employee = employee; }

int Order::getTotalSum() const { return totalSum; }

void Order::setTotalSum(int totalSum) { this->totalSum = totalSum; }

string Order::getRemarks() const { return remarks; }

void Order::setRemarks(const string &remarks) { this->remarks = remarks; }

string Order::statusToString(Status stat) {
    switch (stat) {
        case Status::Reservation:
            return "Reservation";
        case Status::Order:
            return "Order";
        case Status::Completed:
            return "Completed";
        default:
            return "Unknown";
    }
}

void Order::printDetails() const {
    cout << "Number of the order: " << orderNumber << endl;
    cout << "Date of the order: " << orderDate.day << "." << orderDate.month << "." << orderDate.year << endl;
    cout << "Status: " << statusToString(status) << endl;
    cout << "Car: " << orderedCar.getModel() << endl;
    cout << "Start-date: " << begin.day << "." << begin.month << "." << begin.year << endl;
    cout << "End-date: " << end.day << "." << end.month << "." << end.year << endl;
    cout << "Customer: " << customer.getName() << endl;
    cout << "Employee: " << employee.getName() << endl;
    cout << "Total Cost: " << totalSum << endl;
    cout << "Remarks: " << remarks << endl;
}