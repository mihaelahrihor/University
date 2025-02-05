#include "product.h"

Product::Product(const std::string &name, const std::string &origin, int quantity, float price, int day, int month, int year)
        : name(name), origin(origin), quantity(quantity), price(price), expDate(expDate) {
    this -> expDate.day = day;
    this -> expDate.month = month;
    this -> expDate.year = year;
}

std::string Product::getName() const {
    return name;
}

void Product::setName(const std::string &name) {
    this -> name = name;
}

std::string Product::getOrigin() const {
    return origin;
}

void Product::setOrigin(const std::string &origin) {
    this -> origin = origin;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int quantity) {
    this -> quantity = quantity;
}

float Product::getPrice() const {
    return price;
}

void Product::setPrice(float price) {
    this -> price = price;
}

Product::expirationDate Product::getExpirationDate() const {
    return expDate;
}

void Product::setExpirationDate(int day, int month, int year) {
    this -> expDate.day = day;
    this -> expDate.month = month;
    this -> expDate.year=year;
}