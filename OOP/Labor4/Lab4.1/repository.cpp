#include "repository.h"

void Repository::addOrUpdateProduct(const Product &product) {
    bool found = false;
    // verificam numele si originea fiecarui produs
    // daca gasim produsul cautat actualizam cantitatea
    for (auto p : products){
        if (p.getName() == product.getName() && p.getOrigin() == product.getOrigin()) {
            p.setQuantity(p.getQuantity() + product.getQuantity());
            found = true;
            break;
        }
    }
    // daca nu am gasit produsul in lista il vom adauga folosind metoda 'push_back'
    if (!found){
        products.push_back(product);
    }
}

void Repository::removeProduct(const std::string &name, const std::string &origin) {
    // creem o lista noua de produse, initial goala
    std::vector<Product> updatedProductes;
    // cand gasim un produs cu numele sau originea diferita il adaugam in noua lista
    // excludem astfel produsul pe care dorim sa il eliminam
    for (auto p : products){
        if (!(p.getName() == name && p.getOrigin() == origin)){
            products.push_back(p);
        }
    }
    // actualizam lista initiala
    products = updatedProductes;
}

std::vector<Product> Repository::sortProductsByExpirationDate() {
    // folosim bubble sort pentru a sorta produsele
    for (int i=0; i<products.size()-1; i++){
        for (int j=0; j<products.size()-i-1; j++){
            if (products[j].getExpirationDate().year > products[j+1].getExpirationDate().year ||
                (products[j].getExpirationDate().year == products[j+1].getExpirationDate().year &&
                 products[j].getExpirationDate().month > products[j+1].getExpirationDate().month) ||
                (products[j].getExpirationDate().year ==products[j+1].getExpirationDate().year &&
                 products[j].getExpirationDate().month == products[j+1].getExpirationDate().month &&
                 products[j].getExpirationDate().day > products[j+1].getExpirationDate().day))
            {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

std::vector<Product> Repository::searchProducts(std::string search_string) {
    // creem un vector nou
    std::vector<Product> result;
    // verificam pe rand daca numele sau originea fiecarui produs contin string-ul cautat
    for (auto p : products){
        // folosim metoda 'push_back' pentru a adauga in vector produsele gasite
        if (p.getName().find(search_string) != std::string::npos ||  p.getOrigin().find(search_string) != std::string::npos){
            result.push_back(p);
        }
    }
    return result;
}

std::vector<Product> Repository::findProductsRunningLow(int input_quantity) {
    // creem un vector nou
    std::vector<Product> result;
    // comparam cantitaea fiecarui produs cu cea ceruta
    for (auto p : products){
        // folosim metoda 'push_back' pentru a adauga in vector produsele gasite
        if (p.getQuantity() < input_quantity){
            result.push_back(p);
        }
    }
    result;
}