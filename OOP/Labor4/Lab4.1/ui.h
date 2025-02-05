#include "controller.h"

class UI{

private:
    Controller controller;

public:
    std::vector<Product> generateSampleData();
    void displayMenu();
    void displayProducts(const std::vector<Product> products);
    void userCommand(char user_input);
   void run();
};