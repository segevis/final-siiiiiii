//
// Created by segev on 2/28/2024.
//

#include "DataBase.h"


DataBase::DataBase()
{
    std::cout <<"data base constructor player" <<std::endl;

    const std::string FILE_PATH_PLAYER = "C:\\Users\\segev\\CLionProjects\\Software engineering principles full power\\player list 12";
    {
        playerList.open(FILE_PATH_PLAYER, std::ios::in);

        if (!playerList) {
            std::cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH_PLAYER
                      << std::endl;
            return;
        }

        playerCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (playerList.peek() != EOF) {
            playerList.getline(temp, 1000);
            playerCounter++;
        }

        playerList.clear(); // Clear the end-of-file flag
        playerList.seekg(0, std::ios::beg);

        playerArray = new Player* [playerCounter];
        char id[50],fName[50],lName[50],date[50],phone[50],userName[50],password[50],address[50],vip[50],gender[50],email[100];

        for (int i = 0; i < playerCounter; ++i)
        {
            playerList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s %s %s %s %s %s", id, fName, lName, date, phone, userName, password, address, vip, gender, email);
            playerArray[i] = new Player(id,fName,lName,date,phone,userName,password,address,vip,gender,email);
        }

    }
    playerList.close();
    printPlayers();

    std::cout <<"data base constructor manager" <<std::endl;
    const std::string FILE_PATH_MANAGER = "C:\\Users\\segev\\CLionProjects\\Software engineering principles full power\\manager list";
    {
        managerList.open(FILE_PATH_MANAGER, std::ios::in);

        if (!managerList)
        {
            std::cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH_PLAYER
                      << std::endl;
            return;
        }
        managerCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (managerList.peek() != EOF) {
            managerList.getline(temp, 1000);
            managerCounter++;
        }

        managerList.clear(); // Clear the end-of-file flag
        managerList.seekg(0, std::ios::beg);

        managerArray = new Manager* [managerCounter];
        char id[50],fName[50],lName[50],date[50],phone[50],userName[50],password[50],address[50],location[50],gender[50],email[100];

        for (int i = 0; i < managerCounter; ++i)
        {
            managerList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s %s %s %s %s %s", id, fName, lName, date, phone, userName, password, address, location, gender, email);
            managerArray[i] = new Manager(id,fName,lName,date,phone,userName,password,address,location,gender,email);
        }

    }
    managerList.close();
    PrintManager();
}


DataBase::~DataBase()
{
    std::cout << "destructor player" << std::endl;

    const std::string FILE_PATH = "C:\\Users\\segev\\CLionProjects\\Software engineering principles full power\\player list 12";

    std::ofstream ofs(FILE_PATH, std::ofstream::out | std::ofstream::trunc);

    if (!ofs.is_open())
    {
        std::cerr << "Error: Unable to open file for writing: " << FILE_PATH << std::endl;
        return;
    }

    for (int i = 0; i < playerCounter; ++i)
    {
        // Store values in temporary variables
        const char* id = playerArray[i]->Get_ID();
        const char* firstName = playerArray[i]->Get_First_Name();
        const char* lastName = playerArray[i]->Get_Last_Name();
        const char* birthday = playerArray[i]->Get_Birthday();
        const char* phone = playerArray[i]->Get_Phone();
        const char* username = playerArray[i]->Get_Username();
        const char* password = playerArray[i]->Get_Password();
        const char* address = playerArray[i]->Get_Address();
        const char* vip = playerArray[i]->Get_VIP();
        const char* gender = playerArray[i]->Get_Gender();
        const char* email = playerArray[i]->Get_Email();

        // Write values to the file
        ofs << id << " " << firstName << " " << lastName << " " << birthday << " "
            << phone << " " << username << " " << password << " " << address << " "
            << vip << " " << gender << " " << email << std::endl;

    }

    ofs.close(); // Close the file after writing

    for (int i = 0; i < playerCounter; ++i)
    {
        delete playerArray[i];
    }
    delete[] playerArray;


    std::cout << "destructor manager" << std::endl;

    const std::string FILE_PATH_MANAGER = "C:\\Users\\segev\\CLionProjects\\Software engineering principles full power\\manager list";

    std::ofstream ofs1(FILE_PATH_MANAGER, std::ofstream::out | std::ofstream::trunc);

    if (!ofs1.is_open())
    {
        std::cerr << "Error: Unable to open file for writing: " << FILE_PATH_MANAGER << std::endl;
        return;
    }

    for (int i = 0; i < managerCounter; ++i)
    {
        // Store values in temporary variables
        const char* id = managerArray[i]->Get_ID();
        const char* firstName = managerArray[i]->Get_First_Name();
        const char* lastName = managerArray[i]->Get_Last_Name();
        const char* birthday = managerArray[i]->Get_Birthday();
        const char* phone = managerArray[i]->Get_Phone();
        const char* username = managerArray[i]->Get_Username();
        const char* password = managerArray[i]->Get_Password();
        const char* address = managerArray[i]->Get_Address();
        const char* vip = managerArray[i]->Get_Location();
        const char* gender = managerArray[i]->Get_Gender();
        const char* email = managerArray[i]->Get_Email();

        // Write values to the file
        ofs1 << id << " " << firstName << " " << lastName << " " << birthday << " "
            << phone << " " << username << " " << password << " " << address << " "
            << address << " " << gender << " " << email << std::endl;

    }

    ofs1.close(); // Close the file after writing

    for (int i = 0; i < managerCounter; ++i)
    {
        delete managerArray[i];
    }
    delete[] managerArray;
}


void DataBase::printPlayers()
{
    for (int i = 0; i < playerCounter; ++i)
    {
        playerArray[i]->print();
    }

}


void DataBase::addPlayer(const Player &newPlayer)
{
// Create a new array with increased size
    auto** newArray = new Player*[playerCounter + 1];

    // Copy existing players to the new array
    for (int i = 0; i < playerCounter; ++i)
    {
        newArray[i] = playerArray[i];
    }

    // Add the new player to the end of the array
    newArray[playerCounter] = new Player(newPlayer);

    // Delete the old array
    delete[] playerArray;

    // Update the playerArray pointer
    playerArray = newArray;

    // Increment the playerCounter
    ++playerCounter;
}


void DataBase::removePlayer(const char* playerID)
{
    // Find the index of the player with the given ID
    int index = -1;
    for (int i = 0; i < playerCounter; ++i)
    {
        if (strcmp(playerArray[i]->Get_ID(), playerID) == 0)
        {
            index = i;
            break;
        }
    }

    // If player found, remove from the array
    if (index != -1)
    {
        // Delete the player at the found position
        delete playerArray[index];

        // Shift the remaining players to fill the gap
        for (int i = index; i < playerCounter - 1; ++i)
        {
            playerArray[i] = playerArray[i + 1];
        }

        // Decrement the playerCounter
        --playerCounter;
    }
    else
    {
        std::cerr << "Error: Player with ID " << playerID << " not found." << std::endl;
    }
}


void DataBase::PrintManager()
{
    for (int i = 0; i < managerCounter; ++i)
    {
        managerArray[i]->print();
    }

}


void DataBase::AddManager(const Manager& newManager)
{
    // Create a new array with increased size
    auto** newArray = new Manager*[managerCounter + 1];

    // Copy existing managers to the new array
    for (int i = 0; i < managerCounter; ++i)
    {
        newArray[i] = managerArray[i];
    }

    // Add the new manager to the end of the array
    newArray[managerCounter] = new Manager(newManager);

    // Delete the old array
    delete[] managerArray;

    // Update the managerArray pointer
    managerArray = newArray;

    // Increment the managerCounter
    ++managerCounter;
}


void DataBase::RemoveManager(const char* managerID)
{
    // Find the index of the manager with the given ID
    int index = -1;
    for (int i = 0; i < managerCounter; ++i)
    {
        if (strcmp(managerArray[i]->Get_ID(), managerID) == 0)
        {
            index = i;
            break;
        }
    }

    // If manager found, remove from the array
    if (index != -1)
    {
        // Delete the manager at the found position
        delete managerArray[index];

        // Shift the remaining managers to fill the gap
        for (int i = index; i < managerCounter - 1; ++i)
        {
            managerArray[i] = managerArray[i + 1];
        }

        // Decrement the managerCounter
        --managerCounter;
    }
    else
    {
        std::cerr << "Error: Manager with ID " << managerID << " not found." << std::endl;
    }
}