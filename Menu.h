//
// Created by segev on 2/29/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MENU_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MENU_H
#include "DataBase.h"


class Menu: public DataBase{
private:
    DataBase main;

public:
    Menu();
    void menu();

};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MENU_H
