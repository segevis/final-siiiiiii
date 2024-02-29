//
// Created by segev on 2/28/2024.
//

#include "Player.h"

void Player::Set_VIP() {
    int choice;
    cout << "Do you want to be a VIP Client: 1 - YES, 2 - NO." << endl;
    cin >> choice;
//    cin >>choice;
    if (choice == 1)
        this->vip = Set_String("Yes");
    else
        this->vip = Set_String("NO");
}

void Player::print()
{
    std::cout << "ID: " << ID << "\n"
              << "First Name: " << first_name << "\n"
              << "Last Name: " << last_name << "\n"
              << "Date: " << birthday << "\n"
              << "Phone: " << phone << "\n"
              << "Username: " << username << "\n"
              << "Password: " << password << "\n"
              << "Address: " << address << "\n"
              << "VIP: " << vip << "\n"
              << "Gender: " << gender << "\n"
              << "Email: " << email << "\n\n";

}

