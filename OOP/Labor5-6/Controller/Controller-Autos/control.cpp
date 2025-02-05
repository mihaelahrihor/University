#include "control.h"


Control::Control() {
    cars = repo.returnList();
}

bool Control::PlateCheck() {
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].getLicensePlate() == "" || cars[i].getLicensePlate().size() != 7) {
            return false;
        }
    }
    return true;
}

bool Control::PlateLettersCheck() {
    for (int i = 0; i < cars.size(); i++) {
        string newWord = "";
        string currentWord = cars[i].getLicensePlate();

        for (int j = 0; j < currentWord.size(); j++) {
            if (isdigit(currentWord[j])) {
                newWord += currentWord[j];
            }
            else if (isalpha(currentWord[j])) {
                newWord += toupper(currentWord[j]);
            }
            else {
                return false;
            }
        }
        cars[i].setLicensePlate(newWord);
    }
    return true;
}

bool Control::YearCheck() {
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].getFirstRegistrationYear() < 2000 || cars[i].getFirstRegistrationYear() > 2025) {
            return false;
        }
    }
    return true;
}

bool Control::KmPriceCheck() {
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].getDailyPrice() < 0 || cars[i].getMileage() < 0) {
            return false;
        }
    }
    return true;
}