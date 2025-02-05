#ifndef GYM_APP_H
#define GYM_APP_H

#include "../Controller/GymController.h"
#include "../UI/GymView.h"

class GymApp {
private:
    GymController controller;
    GymView view;

public:
    void run() ;
};

#endif