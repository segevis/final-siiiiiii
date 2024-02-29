//
// Created by Artiom on 19/02/2024.
//

#include <fstream>
#include "Field.h"

Field::Field(char* nameOfField, char* location, char* typeOfField, int length, int width, float pricePerHour)
{
    this->nameOfField = new char[strlen(nameOfField)+1];
    strcpy(this->nameOfField,nameOfField);

    this->location = new char[strlen(location)+1];
    strcpy(this->location,location);

    this->typeOfField = new char[strlen(typeOfField)+1];
    strcpy(this->typeOfField,typeOfField);

    this->width=width;
    this->length=length;
    this->pricePerHour=pricePerHour;
    for (int i = 0; i < 15; ++i) {
        isHourReserved[i] = false;
    }
}

void Field::readFromScheduleFile()
{

        const std::string FILE_PATH = "C:\\Users\\Artiom\\CLionProjects\\work-fix\\schedule list";
        std::ifstream scheduleFile(FILE_PATH);

        if (!scheduleFile.is_open()) {
            std::cout << "Error opening schedule file." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(scheduleFile, line)) {
            std::cout << line << std::endl;  // Print each line to the console
        }

        scheduleFile.close();

}


void Field::writeScheduleToFile()
{
    const string FILE_PATH = "C:\\Users\\Artiom\\CLionProjects\\work-fix\\schedule list";
    ofstream scheduleFile(FILE_PATH, ios::app);
    if (!scheduleFile.is_open()) {
        cout << "Error opening schedule file." << endl;
        return;
    }
    scheduleFile << "+---------------------------------------+\n";
    scheduleFile << "| Field Name | Location | Type of Field |\n";
    scheduleFile << "+---------------------------------------+\n";
    scheduleFile << "| " << setw(11) << nameOfField << "  | " << setw(8) << location << " | " << setw(13) << typeOfField << " |\n";

    // Print time slots

    scheduleFile << "+---------------------------------------------------------------------------------------------------------------+" << endl;
    scheduleFile << "| Hour          | Availability   | ID              | First Name      | Last Name       | Equipment Rented       |" << endl;
    scheduleFile << "+---------------------------------------------------------------------------------------------------------------+" << endl;

    for (int hour = 8; hour <= 22; ++hour) {
        scheduleFile << "| " << setw(2) << hour << ":00 - " << setw(2) << hour + 1 << ":00 | ";

        // Check if the hour is within valid range
        if (isAvailable(hour)) {
            scheduleFile << "Available      |                 |                 |                 |                        |" << endl;
        } else {
            scheduleFile << "Reserved       | " << setw(16) << left << reservations[hour-8].getPlayer()->Get_ID() << "| " << setw(16) << left << reservations[hour-8].getPlayer()->Get_First_Name()  << "| " << setw(16) << left << reservations[hour-8].getPlayer()->Get_Last_Name()  << "| " << setw(23) << left << reservations[hour-8].getEquipmentRented() << "|" << endl;
        }
    }

    scheduleFile << "+---------------------------------------------------------------------------------------------------------------+" << endl;
    scheduleFile << endl;
    scheduleFile.close();
}


Field::Field(const Field &other)
{
    nameOfField = new char[strlen(other.nameOfField)+1];
    strcpy(nameOfField,other.nameOfField);

    location = new char[strlen(other.location)+1];
    strcpy(location,other.location);

    typeOfField = new char[strlen(other.typeOfField)+1];
    strcpy(typeOfField,other.typeOfField);

    width=other.width;
    length=other.length;
    pricePerHour=other.pricePerHour;
}


void Field::printDetails()
{
    cout << "Field Name: " << nameOfField << endl;
    cout << "Location: " << location << endl;
    cout << "Type: " << typeOfField << endl;
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Price per hour is: " << pricePerHour << endl;
}


void Field::markAsReserved(int hour, Player* player,char* rentEquipment)
{
    // Check if the hour is within valid range
    if (hour >= 8 && hour <= 22) {
        isHourReserved[hour - 8] = true;
        reservations[hour-8].setAll(hour,player,rentEquipment);
    }
}


void Field::displaySchedule()
{
    cout << "Schedule for " << nameOfField << ":" << endl;
    cout << "+---------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "| Hour          | Availability   | ID              | First Name      | Last Name       | Equipment Rented       |" << endl;
    cout << "+---------------------------------------------------------------------------------------------------------------+" << endl;

    for (int hour = 8; hour <= 22; ++hour) {
        cout << "| " << setw(2) << hour << ":00 - " << setw(2) << hour + 1 << ":00 | ";

        // Check if the hour is within valid range
        if (isAvailable(hour)) {
            cout << "Available      |                 |                 |                 |                        |" << endl;
        } else {
            cout << "Reserved       | " << setw(16) << left << reservations[hour-8].getPlayer()->Get_ID() << "| " << setw(16) << left << reservations[hour-8].getPlayer()->Get_First_Name()  << "| " << setw(16) << left << reservations[hour-8].getPlayer()->Get_Last_Name()  << "| " << setw(23) << left << reservations[hour-8].getEquipmentRented() << "|" << endl;
        }
    }

    cout << "+---------------------------------------------------------------------------------------------------------------+" << endl;
}


bool Field::isAvailable(int hour) const
{
    // Check if the hour is within valid range
    if (hour < 8 || hour > 22)
    {
        return false;
    }

    // Check if the hour is available
    return isHourReserved[hour - 8] == false;
}


bool Field::reserveField(int hour, Player* player, char* rentEquipment) {
    // Check if the hour is within valid range
    if (hour < 8 || hour > 22) {
        cout << "Invalid hour for reservation." << endl;
        return false;
    }

    // Check if the hour is available
    if (!isAvailable(hour)) {
        cout << "Field is already reserved at " << hour << ":00." << std::endl;
        return false;
    }

    // Make the reservation
    markAsReserved(hour,player,rentEquipment);

    // Update the schedule file
    //writeScheduleToFile();

    cout << "Reservation successful for " << nameOfField << " at " << hour << ":00." << std::endl;
    return true;
}

void Field::showPlayerOrderHistory(const string& playerId) const
{
    const std::string FILE_PATH = "C:\\Users\\Artiom\\CLionProjects\\work-fix\\schedule list";
    std::ifstream inputFile(FILE_PATH);
    if (!inputFile.is_open()) {
        std::cout << "Error opening schedule file." << std::endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        // Check if the line contains the player's ID
        if (line.find(playerId) != string::npos) {
            cout << line << endl;
        }
    }
    inputFile.close();
}


void Field::cancelOrderById(const std::string& idToCancel)
{
    const string FILE_PATH = "C:\\Users\\Artiom\\CLionProjects\\work-fix\\schedule list";
    ifstream inputFile(FILE_PATH);
    if (!inputFile.is_open()) {
        cout << "Error opening schedule file." << endl;
        return;
    }

    // Read the existing content into memory
    string fileContent((istreambuf_iterator<char>(inputFile)),istreambuf_iterator<char>());

    // Find the position of the reservation with the specified ID
    size_t idPosition = fileContent.find(idToCancel);
    if (idPosition == string::npos) {
        cout << "Reservation with ID " << idToCancel << " not found." << endl;
        return;
    }

    // Find the start of the line containing the reservation
    size_t lineStart = fileContent.rfind('\n', idPosition) + 1;

    // Find the end of the line containing the reservation
    size_t lineEnd = fileContent.find('\n', idPosition);

    // Erase the line containing the reservation
    fileContent.erase(lineStart, lineEnd - lineStart + 1);

    // Write the modified content back to the file
    ofstream outputFile(FILE_PATH);
    if (!outputFile.is_open()) {
        cout << "Error opening schedule file for writing." << endl;
        return;
    }

    outputFile << fileContent;
    cout << "Order with ID " << idToCancel << " has been canceled." << endl;

    inputFile.close();
    outputFile.close();
}