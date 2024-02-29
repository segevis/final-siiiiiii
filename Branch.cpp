//
// Created by Artiom on 28/02/2024.
//

#include "Branch.h"
Branch& Branch::operator+=(Field* object)
{
    Field** addFieldArr = new Field * [sizeFieldArray+1];
    for (int i = 0; i < sizeFieldArray; ++i)
    {
        addFieldArr[i] = fieldArray[i];
    }
    addFieldArr[sizeFieldArray]=object;
    delete [] fieldArray;
    fieldArray = addFieldArr;
    sizeFieldArray++;
    return *this;
}


void Branch::removeField(Field* object)
{
    if (sizeFieldArray==0)
        return;

    bool found = false;
    for (int i = 0; i < sizeFieldArray; ++i)
    {
        if (fieldArray[i] == object)
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        return;
    }
    Field** NewField = new Field*[sizeFieldArray-1];
    int j=0;
    for (int i = 0; i < sizeFieldArray; ++i)
    {
        if (fieldArray[i]!=object)
        {
            NewField[j]=fieldArray[i];
            j++;
        }
    }
    delete [] fieldArray;
    fieldArray = NewField;
    fieldArray--;
}
