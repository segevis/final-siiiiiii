//
// Created by Artiom on 28/02/2024.
//

#include "Order.h"
Order::Order(const char* customerName,int fieldIndex,int day, int startTime,int endTime)
{
    this->customerName=new char [strlen(customerName)+1];
    strcpy(this->customerName,customerName);

    this->fieldIndex=fieldIndex;
    this->day=day;
    this->startTime=startTime;
    this->endTime=endTime;
}
Order::Order(const Order& other)
{
    customerName=new char [strlen(other.customerName)+1];
    strcpy(customerName,other.customerName);
    fieldIndex=other.fieldIndex;
    day=other.day;
}

//void Order::writeOrder(const char* customerName, int fieldIndex, int day, int startTime, int endTime)
//{
//    const string FILE_PATH1 = "C:\\Users\\Artiom\\CLionProjects\\SportField\\schedule list";
//    ofstream File(FILE_PATH1,ios::app);
//}
