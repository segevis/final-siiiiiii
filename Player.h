//
// Created by segev on 2/28/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_PLAYER_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_PLAYER_H


#include "User.h"

class Player: public User {
private:
    char* vip;
public :
    Player(char *ID) : User(ID)
    {
       Set_VIP();
    }


    Player(char *n_ID, char *f_name, char *l_name, char* birth,
           char *n_phone, char *user, char *password, char *address,
           char *vip, char* gender,char* email)
           : User(n_ID,f_name,l_name,gender,email,n_phone,user,password,address,birth)
           {
                   // Deep copy for vip
                   this->vip = new char[strlen(vip) + 1];
                   strcpy(this->vip, vip);
           }


    ~Player()
    {
    //delete[] vip;
    }

    void Set_VIP();
    char* Get_VIP(){return vip;}
    void print();
};

#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_PLAYER_H
