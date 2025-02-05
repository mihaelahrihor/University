#include "controller.h"

void Controller::addOrUpdateProduct(const std::string &name, const std::string &origin, int quantity, float price, int day, int month, int year) {
    Product product(name, origin, quantity, price, day, month, year);
    repository.addOrUpdateProduct(product);
}

void Controller::removeProduct(const std::string& name, const std::string& origin) {
    repository.removeProduct(name, origin);
}

std::vector<Product> Controller::searchProducts(const std::string& search_string) {
    return repository.searchProducts(search_string);
}

std::vector<Product> Controller::findProductsRunningLow(int input_quantity) {
    return repository.findProductsRunningLow(input_quantity);
}

std::vector<Product> Controller::sortProductsByExpirationDate() {
    return repository.sortProductsByExpirationDate();
}