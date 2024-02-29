//
// Created by Artiom on 29/02/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_RESERVATION_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_RESERVATION_H
#include <iostream>
#include <cstring>
#include "Player.h"

using namespace std;

class Reservation {
private:
    int hour;
    Player* player;
    char* equipmentRented;
public:
    Reservation():hour(0),player(nullptr),equipmentRented(nullptr){}
    Reservation(int hour,Player* player,char* equipmentRented)
    {
        this->hour=hour;
        this->player=player;

        this->equipmentRented=new char[strlen(equipmentRented)+1];
        strcpy(this->equipmentRented,equipmentRented);
    }
    ~Reservation(){
        delete[] equipmentRented;
    }

    void setHour(int hour) { this->hour = hour; }

    void setPlayer(Player* player) { this->player = player; }

    void setEquipmentRented(char* equipmentRented) {
        if(this->equipmentRented != nullptr)
            delete[] this->equipmentRented;
        this->equipmentRented=new char[strlen(equipmentRented)+1];
        strcpy(this->equipmentRented,equipmentRented);
    }

    void setAll(int hour,Player* player,char* equipmentRented)
    {
        setHour(hour);
        setPlayer(player);
        setEquipmentRented(equipmentRented);
    }

    int getHour() {return hour;}
    Player* getPlayer() {return player;}
    char* getEquipmentRented() {return equipmentRented;}

};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_RESERVATION_H
