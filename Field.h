//
// Created by Artiom on 19/02/2024.
//

#ifndef USER_H_FIELD_H
#define USER_H_FIELD_H
using namespace std;
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Player.h"
#include "Reservation.h"


class Field {
protected:
    char* nameOfField ;
    char* location;
    char* typeOfField;
    int length, width;
    float pricePerHour;
    bool isHourReserved[15];
    Reservation reservations[15];

public:
    Field():nameOfField(nullptr),location(nullptr),typeOfField(nullptr),length(0),width(0),pricePerHour(0.0){
        for (int i = 0; i < 15; ++i) {
            isHourReserved[i] = false;
        }
    }
    Field(char* nameOfField,char* location,char* typeOfField,int length, int width,float pricePerHour);
    Field(const Field &other);
    virtual ~Field(){delete[] nameOfField;}
    void printDetails();
    char* getNameOfField()const{return nameOfField;}
    void writeScheduleToFile();
    void readFromScheduleFile();
    void showPlayerOrderHistory(const string& playerId) const;
    char* getLocation()const{return location;}
    char* getTypeOfField()const{return typeOfField;}
    int getLength()const{return length;}
    int getWidth()const{return width;}
    float getPricePerHour()const{return pricePerHour;}
    void markAsReserved(int hour, Player* player, char* rentEquipment);
    bool isAvailable(int hour) const;
    void displaySchedule() ;
    bool reserveField(int hour, Player* player, char* rentEquipment);
    void cancelOrderById(const string &idToCancel);
};


#endif //USER_H_FIELD_H
