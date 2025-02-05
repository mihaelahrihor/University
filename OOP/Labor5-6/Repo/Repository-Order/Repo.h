#ifndef CARSHARING_712_1_REPO_H
#define CARSHARING_712_1_REPO_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "../Domain-Order/Order.h"

using namespace std;

class OrderRepo {
private:
    vector<Order> orders;

public:
    OrderRepo();
    void createOrder(Order order, bool isEmployee);
    void modifyOrder(Order order, string employeeStatus, string employeeName, Status status, Date end);
};

#endif //CARSHARING_712_1_REPO_H
