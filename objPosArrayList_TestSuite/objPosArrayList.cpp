#include "objPosArrayList.h"
// #include <iostream>
// using namespace std;
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        //cout << "Array is Full!" << endl;
        return;
    }

    // Shifting/Pushing all elements back by one slot
    // Overwriting the value in i+1 position with that in i position
    for(int i=listSize; i>0; i--)
    {
        aList[i] = aList[i-1]; // Shifting all elements towards the tail to create space at the head
    }
    // aList[0] is ready to be OVERWRITTEN by incoming value

    aList[0] = thisPos; // Inserting the element at the head, index: 0
    listSize++;     // Increase the size of the List by one
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        //cout << "Array is Full!" << endl;
        return;
    }
    
    aList[listSize] = thisPos;  // Inserting the element at the tail, index: sizeList
    listSize++;     // Increase the size of the List by one

}

void objPosArrayList::removeHead()
{
    if(listSize == 0)
    {
        //cout << "List is Empty, No Removal Allowed!" << endl;
        return;
    }

    for(int i=0; i<listSize-1; i++)
    {
        aList[i] = aList[i+1];  // Shifting towards the head, element i replaced by element i+1
    }
    listSize--; // Decrease the size of the list by one
}

void objPosArrayList::removeTail()
{
    if(listSize == 0)
    {
        //cout << "List is Empty, No Removal Allowed!" << endl;
        return;
    }

    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    // if(index<0 || index >= listSize)
    // {
    //     cout << "You have supplied an invalid index." << endl;
    //     return;
    // }

    return aList[index];
}