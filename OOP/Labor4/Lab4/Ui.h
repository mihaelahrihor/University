#include "Controller.h"

class Ui{

private:
    Controller controller;

public:
    std::vector<Produckt>generateSampleData();
    void displayMenu();
    void displayProd(const std::vector<Produckt>products);
    void userCommand(char user_input);
    void run();
};