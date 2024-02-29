//
// Created by segev on 2/28/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "Player.h"
#include "Manager.h"


class DataBase {

protected:

    std::fstream playerList;
    int playerCounter;
    Player** playerArray;

    std::fstream managerList;
    int managerCounter;
    Manager** managerArray;

public:
    DataBase();
    ~DataBase();

    void addPlayer(const Player& newPlayer);
    void removePlayer(const char *playerID);
    void printPlayers();

    void AddManager(const Manager &newManager);
    void RemoveManager(const char *ManagerID);
    void PrintManager();

    int getPlayerCounter() const  {return playerCounter;}
    Player** getPlayerList() {return playerArray;}
//    void setPlayerCounter(){ playerCounter++;}
    Manager** getManagerlist() {return  managerArray;}
    int getManagerCounter() const {return managerCounter;}

};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
