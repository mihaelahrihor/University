#include "Repo.h"

OrderRepo::OrderRepo() {

};

void OrderRepo::createOrder(Order order, bool isEmployee) {
    if (!isEmployee) {
        throw invalid_argument("Only employees are allowed to create orders.");
    }
    orders.push_back(order);
}

void OrderRepo::modifyOrder(Order order, string employeeStatus, string employeeName, Status status, Date end) {
    if (order.statusToString(order.getStatus()) == "Completed") {
        throw invalid_argument("Order already completed!");
    }
    if (order.getEmployee().getName() != employeeName || employeeStatus != "Admin") {
        throw invalid_argument("Not your order!");
    }

    order.setStatus(status);
    order.setEnd(end);
}