#include "Ui.h"
#include <iostream>
#include <string>

void Ui::run() {
    std::vector<Produckt> sampleProducts = generateSampleData();
    for (const auto& p : sampleProducts){
        auto expDate = p.getExpirationDate();
        controller.AddOrUpdate(p.getName(), p.getOrigin(), p.getQuantity(), p.getPrice(), expDate.day, expDate.month, expDate.year);
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

void Ui::displayMenu() {
    std::cout << "1. Search products\n";
    std::cout << "2. List products running low\n";
    std::cout << "3. Sort products by expiration date\n";
    std::cout << "4. Quit\n";
}

void Ui::userCommand(char user_input) {
    switch (user_input) {
        case '1': {
            std::string string_to_search;
            std::cout << "Enter a string to search by: ";
            std::getline(std::cin, string_to_search);
            std::vector<Produckt> result_after_search = controller.searchProd(string_to_search);
            displayProd(result_after_search);
            break;
        }
        case '2': {
            int quantity_to_search;
            std::cout << "Enter quantity to search by: ";
            std::cin >> quantity_to_search;
            std::vector<Produckt> results_after_search = controller.findProdRunningLow(quantity_to_search);
            displayProd(results_after_search);
            break;
        }
        case '3': {
            std::vector<Produckt> sortedProducts = controller.sortProdByExpDay();
            displayProd(sortedProducts);
            break;
        }
        case '4':
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}

std::vector<Produckt> Ui::generateSampleData() {
    std::vector<Produckt> sampleProducts;
    sampleProducts.push_back(Produckt("Decasept", "origin1", 30, 25.5, 12, 3, 2028));
    sampleProducts.push_back(Produckt("Paracetamol", "origin2", 35, 23.9, 8, 9, 2027));
    sampleProducts.push_back(Produckt("Brufen", "origin3", 22, 34.3, 14, 11, 2028));
    sampleProducts.push_back(Produckt("Voltaren", "origin2", 27, 29.9, 10, 12, 2025));
    sampleProducts.push_back(Produckt("Strepsils", "origin4", 14, 27.5, 27, 4, 2026));

    return sampleProducts;
}

void Ui::displayProd(const std::vector<Produckt> products) {
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