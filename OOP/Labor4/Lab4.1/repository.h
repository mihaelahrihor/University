#include "product.h"
#include <vector>

class Repository{

private:
    // vectorul 'products' va contine obiecte de tipul Product
    std::vector<Product> products;

public:
    // metoda adaugare sau actualizare produs
    void addOrUpdateProduct(const Product& product);

    // metoda stergere produs
    void removeProduct(const std::string& name, const std::string& origin);

    // metoda sortare produse dupa data de expirare (crescator)
    std::vector<Product> sortProductsByExpirationDate();

    // metoda cautare produse dupa un string
    std::vector<Product> searchProducts(std::string search_string);

    // metoda cautare produse dupa cantitate (cantitate < valoare data de utilizator)
    std::vector<Product> findProductsRunningLow(int input_quantity);
};