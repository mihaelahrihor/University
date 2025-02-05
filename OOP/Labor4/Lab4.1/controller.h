#include "repository.h"

class Controller {

private:
    Repository repository;

public:
    void addOrUpdateProduct(const std::string& name, const std::string& origin, int quantity, float price, int day, int month, int year);
    void removeProduct(const std::string& name, const std::string& origin);
    std::vector<Product> searchProducts(const std::string& search_string);
    std::vector<Product> findProductsRunningLow(int input_quantity);
    std::vector<Product> sortProductsByExpirationDate();
};