#include "ui.h"
#include <iostream>
#include <string>

void UI::run() {
    std::vector<Product> sampleProducts = generateSampleData();
    for (const auto& p : sampleProducts){
        auto expDate = p.getExpirationDate();
        controller.addOrUpdateProduct(p.getName(), p.getOrigin(), p.getQuantity(), p.getPrice(), expDate.day, expDate.month, expDate.year);
    }
    char user_input;
    do {
        displayMenu();
        std::cout << "Enter your choice (1 or 2 or 3 or 4): ";
        std::cin >> user_input;
        std::cin.ignore(); // ignoram newline-ul ramas
        userCommand(user_input);
    } while (user_input != '4');
}

void UI::displayMenu() {
    std::cout << "\n=== Menu ===\n";
    std::cout << "1. Search products\n";
    std::cout << "2. List products running low\n";
    std::cout << "3. Sort products by expiration date\n";
    std::cout << "4. Quit\n";
}

void UI::userCommand(char user_input) {
    switch (user_input) {
        case '1': {
            std::string string_to_search;
            std::cout << "Enter a string to search by: ";
            std::getline(std::cin, string_to_search);
            std::vector<Product> results_after_search = controller.searchProducts(string_to_search);
            displayProducts(results_after_search);
            break;
        }
        case '2': {
            int quantity_to_search;
            std::cout << "Enter quantity to search by: ";
            std::cin >> quantity_to_search;
            std::vector<Product> results_after_search = controller.findProductsRunningLow(quantity_to_search);
            displayProducts(results_after_search);
            break;
        }
        case '3': {
            std::vector<Product> sortedProducts = controller.sortProductsByExpirationDate();
            displayProducts(sortedProducts);
            break;
        }
        case '4':
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}

std::vector<Product> UI::generateSampleData() {
    std::vector<Product> sampleProducts;
    sampleProducts.push_back(Product("Nurofen", "origin1", 30, 25.5, 12, 3, 2028));
    sampleProducts.push_back(Product("Paracetamol", "origin2", 35, 23.9, 8, 9, 2027));
    sampleProducts.push_back(Product("Parasinus", "origin3", 22, 34.3, 14, 11, 2028));
    sampleProducts.push_back(Product("Algocalmin", "origin2", 27, 29.9, 10, 12, 2025));
    sampleProducts.push_back(Product("Augmentin", "origin4", 14, 27.5, 27, 4, 2026));
    sampleProducts.push_back(Product("NoSpa", "origin1", 42, 19.9, 1, 10, 2028));
    sampleProducts.push_back(Product("Detralex", "origin5", 9, 22.7, 4, 4, 2029));
    sampleProducts.push_back(Product("Septolete", "origin6", 12, 21.5, 3, 6, 2027));
    sampleProducts.push_back(Product("Aspirina", "origin1", 47, 15.5, 2, 2, 2026));
    sampleProducts.push_back(Product("Panadol", "origin6", 36, 25.0, 14, 12, 2025));
    return sampleProducts;
}

void UI::displayProducts(const std::vector<Product> products) {
    if (products.empty()){
        std::cout << "No products found\n";
        return;
    }
    std::cout << "\n=== Menu ===\n";
    for (const auto& product : products){
        std::cout << "Name: " << product.getName() << "\n";
        std::cout << "Origin: " << product.getOrigin() << "\n";
        std::cout << "Quantity: " << product.getQuantity() << "\n";
        std::cout << "Price: " << product.getPrice() << "\n";
        auto expDate = product.getExpirationDate();
        std::cout << "Expiration date: " << expDate.day << "/" << expDate.month << "/" << expDate.year <<"\n\n";
        }
}