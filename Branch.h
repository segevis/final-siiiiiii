//
// Created by Artiom on 28/02/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_BRANCH_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_BRANCH_H
#include "Field.h"


class Branch {
protected:
    Field** fieldArray;
    int branchId;
    int sizeFieldArray;

public:
    Branch():fieldArray(nullptr),branchId(0),sizeFieldArray(0){}
    ~Branch(){
        for (int i = 0; i < sizeFieldArray; ++i)
        {
            delete fieldArray[i];
        }
        delete [] fieldArray;
    }
    int getBranchID()const{return branchId;}
    int getSizeFieldArray()const{return sizeFieldArray;}
    void printDetails()const;
    Branch &operator +=(Field* object);
    void removeField(Field* object);
};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_BRANCH_H
