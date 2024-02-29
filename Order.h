//
// Created by Artiom on 28/02/2024.
//

#ifndef MAIN_CPP_ORDER_H
#define MAIN_CPP_ORDER_H
#include <iostream>
#include <cstring>
using namespace std;

class Order {
protected:
    char* customerName;
    int fieldIndex;
    int day;
    int startTime;
    int endTime;
public:
    Order():customerName(nullptr),fieldIndex(0),day(0),startTime(0),endTime(0){}
    Order(const char* customerName,int fieldIndex,int day, int startTime,int endTime);
    Order(const Order& other);
    ~Order() { delete[] customerName; }
    char* getCustomerName() const { return customerName; }
    void writeOrder(const char* customerName, int fieldIndex, int day, int startTime, int endTime);
    int getFieldIndex() const { return fieldIndex; }
    int getDay() const { return day; }
    int getStartTime() const { return startTime; }
    int getEndTime() const { return endTime; }

    void printDetails() const {
        cout << "Customer name is: " << customerName << endl;
        cout << "Day " << day << ", Start Time: " << startTime << ":00, End Time: " << endTime << ":00" << endl;
    }
};


#endif //MAIN_CPP_ORDER_H
