//
// Created by segev on 2/29/2024.
//

#include "Menu.h"
//
//static bool Blank_Line(int len)
//{
//    if (len == 0) {
//        cout << "You entered a blank line, please try again." << endl;
//        return true;
//    }
//    return false;
//
//}
//char *Set_String(char* str)
//{
//    char *res = new char[strlen(str) + 1];
//    strcpy(res, str);
//    return res;
//}
//static bool Check_Number(char ch) { return ((ch >= '0') && (ch <= '9')); } // Checked
//bool check_ID(char*& Id)
//{
//    getchar();
//    char ID_check[MAX];
//    cout << "Enter an ID, must be only 9 digits" << endl;
//    cin.getline(ID_check, MAX);
//    int len = int(strlen(ID_check));
//    if (Blank_Line(len))
//        return false;
//    if (len != ID_LIM) {
//        cout << "You enter incorrect number of digits, please try again." << endl;
//        return false;
//    }
//    for (int i = 0; i < len; ++i) {
//        if (!Check_Number(ID_check[i])) {
//            cout << "You entered incorrect char, please try again." << endl;
//            return false;
//        }
//    }
//    Id = Set_String(ID_check);
//    return true;
//}



Menu::Menu()
{
    std::cout << "menu constarctor" <<std::endl;
    main;

}

void Menu::menu()
{
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

            switch (choice)
            {
                case 1:
                {
                    std::cout << "Welcome !\n"
                                 "In order to complete your registration as a new member in our system,\n"
                                 "we need some additional details from you.\n";
                    std::cout << "Insert an ID card to check if you exist in the system:" <<std::endl;
                    char* id = nullptr;
                    //while (!check_ID(id));
                    bool flag = false;

                    for (int i = 0; i < getPlayerCounter(); ++i)
                    {
                        if(strcmp(playerArray[i]->Get_ID(),id) == 0)
                        {
                            std::cout << "You exist in the system!" <<std::endl;
                            flag = true;
                            break;
                        }

                    }
                    if (!flag)
                    {
                        Player newPlayer(id);
                        main.addPlayer(newPlayer);
                        main.printPlayers();
                        std::cout << "Welcome you have successfully registered you can log in." << std::endl;

                    }
                    delete[] id;
                    break;
                }
                case 2:
                {
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

}


