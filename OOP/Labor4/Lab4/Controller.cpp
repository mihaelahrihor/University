#include "Controller.h"

void Controller::AddOrUpdate(const std::string &name, const std::string &origin, int quantity, float price, int day,
                             int month, int year) {
    Produckt produckt(name, origin, quantity, price, day, month, year);
    repo.AddOrUpdate(produckt);
}

void Controller::removeProd(const std::string &name, const std::string &origin) {
    repo.remove(name, origin);
}

std::vector<Produckt>Controller::searchProd(const std::string& search_string) {
    return repo.searchProd(search_string);
}

std::vector<Produckt>Controller::findProdRunningLow(int input_quantity) {
    return repo.findProdRunningLow(input_quantity);
}

std::vector<Produckt>Controller::sortProdByExpDay() {
    return repo.sortByExpDate();
}
