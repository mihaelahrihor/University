#include "Product.h"

Produckt::Produckt(const std::string& name, const std::string& origin, int quantity, float price, int day, int month,
                   int year) :name(name),origin(origin),quantity(quantity),price(price), expDate(expDate){
    this->expDate.day=day;
    this->expDate.month=month;
    this->expDate.year=year;
}

std::string Produckt::getName() const {
    return name;
}

void Produckt::setName(const std::string& name) {
    this->name=name;
}

std::string Produckt::getOrigin() const {
    return origin;
}

void Produckt::setOrigin(const std::string& origin)  {
    this->origin=origin;
}

int Produckt::getQuantity() const {
    return quantity;
}

void Produckt::setQuantity(int quantity) {
    this->quantity=quantity;
}

float Produckt::getPrice() const {
    return price;
}

void Produckt::setPrice(float price) {
    this->price=price;
}

Produckt::expirationDate Produckt::getExpirationDate() const {
    return expDate;
}

void Produckt::setExpirationDate(int day, int month, int year) {
    this->expDate.day=day;
    this->expDate.month=month;
    this->expDate.year=year;
}