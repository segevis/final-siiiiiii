//
// Created by segev on 2/28/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MANAGER_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MANAGER_H


#include "User.h"

class Manager: public User {

private:
    char* location;

public:
    Manager(char * newID):User(newID){Set_Location();}
    Manager(char *n_ID, char *f_name, char *l_name, char* birth,
                char *n_phone, char *user, char *password, char *address,
                char *Location, char* gender,char* email)
    : User(n_ID,f_name,l_name,gender,email,n_phone,user,password,address,birth)
    {
        location = new char[strlen(Location) + 1];
        strcpy(location, Location);
    }


    bool Set_Location()
    {
        char temp[MAX];
        cout << "Enter location: ";
        cin.getline(temp, MAX);

        // You might want to add additional validation for the location if needed

        // Set the location
        location = Set_String(temp);
        return true;  // Assuming successful setting of location
    }

    char* Get_Location()
    {
        return location;
    }


    void print()
    {
        std::cout << "ID: " << ID << "\n"
                  << "First Name: " << first_name << "\n"
                  << "Last Name: " << last_name << "\n"
                  << "Date: " << birthday << "\n"
                  << "Phone: " << phone << "\n"
                  << "Username: " << username << "\n"
                  << "Password: " << password << "\n"
                  << "Address: " << address << "\n"
                  << "location: " << location << "\n"
                  << "Gender: " << gender << "\n"
                  << "Email: " << email << "\n\n";
    }
};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MANAGER_H
