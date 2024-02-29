#include <iostream>
#include "DataBase.h"
#include "Player.h"

static bool Blank_Line(int len)
{
    if (len == 0) {
        cout << "You entered a blank line, please try again." << endl;
        return true;
    }
    return false;

}
char *Set_String(char* str)
{
    char *res = new char[strlen(str) + 1];
    strcpy(res, str);
    return res;
}
static bool Check_Number(char ch) { return ((ch >= '0') && (ch <= '9')); } // Checked
bool check_ID(char*& Id)
{
    getchar();
    char ID_check[MAX];
    cout << "Enter an ID, must be only 9 digits" << endl;
    cin.getline(ID_check, MAX);
    int len = int(strlen(ID_check));
    if (Blank_Line(len))
        return false;
    if (len != ID_LIM) {
        cout << "You enter incorrect number of digits, please try again." << endl;
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (!Check_Number(ID_check[i])) {
            cout << "You entered incorrect char, please try again." << endl;
            return false;
        }
    }
    Id = Set_String(ID_check);
    return true;
}

void EditUsername(int index, DataBase &dataBae)
{
    while(!dataBae.getPlayerList()[index]->Set_Username());
    std::cout << "Username updated successfully!\n";
}
void EditPassword(int index, DataBase &dataBae)
{
    while(!dataBae.getPlayerList()[index]->Get_Password());
    std::cout << "Password updated successfully!\n";
}
void EditAddress(int index, DataBase &dataBae)
{
    while (!dataBae.getPlayerList()[index]->Set_Address())
    std::cout << "Address updated successfully!\n";
}
void EditPhoneNumber(int index, DataBase &dataBae)
{
    while (!dataBae.getPlayerList()[index]->Set_Phone());
    std::cout << "Phone number updated successfully!\n";
}
void EditPersonalDetails(int index, DataBase &dataBae)
{
    int editChoice;
    do {
        std::cout << "\nEdit Personal Details:\n";
        std::cout << "1. Edit Username\n";
        std::cout << "2. Edit Password\n";
        std::cout << "3. Edit Address\n";
        std::cout << "4. Edit Phone Number\n";
        std::cout << "5. Back to Player Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> editChoice;

        switch (editChoice) {
            case 1:
                EditUsername(index,dataBae);
                break;
            case 2:
                EditPassword(index,dataBae);
                break;
            case 3:
                EditAddress(index,dataBae);
                break;
            case 4:
                EditPhoneNumber(index,dataBae);
                break;
            case 5:
                std::cout << "Returning to Player Menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (editChoice != 5);
}


void playerMenu(int index, DataBase &dataBae)
{
    int choice;
    do {
        std::cout << "\nPlayer Menu:\n";
        std::cout << "1. View Profile\n";
        std::cout << "2. Edit Personal Details\n";  // New option
        std::cout << "3. Book a Field\n";
        std::cout << "4. View Booking History\n";
        std::cout << "5. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Viewing Profile...\n";
                dataBae.getPlayerList()[index]->print();
                break;
            case 2:
                std::cout << "Editing Personal Details...\n";
                EditPersonalDetails(index,dataBae);
                break;
            case 3:
                std::cout << "Booking a Field...\n";
                // Call a function to handle field booking
                break;
            case 4:
                std::cout << "Viewing Booking History...\n";
                // Call a function to display booking history
                break;
            case 5:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}


int main() {
    DataBase D;



    int choice;
    do {
        std::cout << "Hello ! Welcome to Sami Sports Field Rental.\n"
                     "If you are an existing member in the system press 1. \n"
                     "for New member press 2.\n";
        std::cin >> choice;

        if (choice != 1 && choice != 2)
            std::cout << "The selection is not supported by the system. Please select again.\n";

    } while (choice != 1 && choice != 2);

    switch (choice)
    {
        case 1:
        {
            bool flag = false;
            do {
                std::cout << "Welcome back!\n"
                             "To sign in as a new player press 1\n"
                             "To sign in as a new manager press 2\n";
                std::cin  >> choice;

                if (choice != 1 && choice != 2)
                    std::cout << "The selection is not supported by the system. Please select again.\n";

            } while (choice != 1 && choice != 2);
            do
            {
                char usernameC[100], passwordC[100];
                int index_pass = -2, index_user = -1;
                cout << "Enter your User name" << endl;
                cin >> usernameC;
                cout << "Enter your Password" <<endl;
                cin >> passwordC;
                switch (choice) {
                    case 1:
                    {
                        for (int i = 0; i < D.getPlayerCounter(); ++i)
                        {
                            if (strcmp(D.getPlayerList()[i]->Get_Username(), usernameC) == 0)
                                index_user = i;
                            if (strcmp(D.getPlayerList()[i]->Get_Password(), passwordC) == 0)
                                index_pass = i;
                        }
                        if (index_pass == -2 || index_user == -1)
                            cout << "You entered incorrect number" << endl;
                        else if (index_user == index_pass) {
                            cout << "You login successfully!" << endl;
                            Player loggedInPlayer
                            (
                                    D.getPlayerList()[index_user]->Get_ID(),
                                    D.getPlayerList()[index_user]->Get_First_Name(),
                                    D.getPlayerList()[index_user]->Get_Last_Name(),
                                    D.getPlayerList()[index_user]->Get_Birthday(),
                                    D.getPlayerList()[index_user]->Get_Phone(),
                                    D.getPlayerList()[index_user]->Get_Username(),
                                    D.getPlayerList()[index_user]->Get_Password(),
                                    D.getPlayerList()[index_user]->Get_Address(),
                                    D.getPlayerList()[index_user]->Get_VIP(),
                                    D.getPlayerList()[index_user]->Get_Gender(),
                                    D.getPlayerList()[index_user]->Get_Email()

                            );
                            playerMenu(index_user,D);
                        }
                        else
                            cout << "The username and password aren't match" << endl;

                        break;
                    }
                    case 2:
                    {
                        for (int i = 0; i < D.getManagerCounter(); ++i)
                        {
                            if (strcmp(D.getManagerlist()[i]->Get_Username(), usernameC) == 0)
                                index_user = i;
                            if (strcmp(D.getManagerlist()[i]->Get_Password(), passwordC) == 0)
                                index_pass = i;
                        }
                        if (index_pass == -2 || index_user == -1)
                            cout << "You entered in correct number" << endl;
                        else if (index_user == index_pass) {
                            cout << "You login successfully!" << endl;
                            flag = true;
                        }
                        else
                            cout << "The username and password aren't match" << endl;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                if (!flag) {
                    int check;
                    do {
                        cout << "If you want to try again please enter 1 else 2" << endl;
                        cin >> check;
                        if (check != 1 && check != 2)
                            cout << "incorrect option please try again." << endl;
                        else if (check == 2)
                            flag = true;
                    } while (check != 1 && check != 2);
                }
            }while (!flag);

            break;
        }
        case 2:
        {
            do {
                std::cout << "Glad you decided to join us!\n"
                             "To register as a new player press 1\n"
                             "To register as a new manager press 2\n";
                std::cin  >> choice;

                if (choice != 1 && choice != 2)
                    std::cout << "The selection is not supported by the system. Please select again.\n";

            } while (choice != 1 && choice != 2);

            switch (choice) {
                case 1: {
                    std::cout << "Welcome !\n"
                                 "In order to complete your registration as a new member in our system,\n"
                                 "we need some additional details from you.\n";
                    std::cout << "Insert an ID card to check if you exist in the system:" << std::endl;
                    char *id = nullptr;
                    while (!check_ID(id));
                    bool flag = false;

                    for (int i = 0; i < D.getPlayerCounter(); ++i) {
                        if (strcmp(D.getPlayerList()[i]->Get_ID(), id) == 0) {
                            std::cout << "You exist in the system!" << std::endl;
                            flag = true;
                            break;
                        }

                    }
                    if (!flag) {
                        Player newPlayer(id);
                        D.addPlayer(newPlayer);
                        D.printPlayers();
                        std::cout << "Welcome you have successfully registered you can log in." << std::endl;

                    }
                    delete[] id;
                    break;
                }
                case 2:{
                    std::cout << "Welcome !\n"
                                 "In order to complete your registration as a new manager in our system,\n"
                                 "we need some additional details from you.\n";
                    std::cout << "Insert an ID number to check if you exist in the system:" << std::endl;
                    char *id = nullptr;
                    while (!check_ID(id));
                    bool flag = false;

                    for (int i = 0; i < D.getManagerCounter(); ++i) {
                        if (strcmp(D.getManagerlist()[i]->Get_ID(), id) == 0) {
                            std::cout << "You exist in the system!" << std::endl;
                            flag = true;
                            break;
                        }

                    }
                    if (!flag) {
                        Manager newManger(id);
                        D.AddManager(newManger);
                        D.PrintManager();
                        std::cout << "Welcome you have successfully registered you can log in." << std::endl;

                    }
                    delete[] id;
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }
    return 0;
}
