#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

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
         return;
    }

    // Shifting/Pushing all elements back by one slot
    // Overwriting the value in i+1 position with that in i position
    for(int i = listSize; i > 0; i--)
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
         return;
    }
    
    aList[listSize] = thisPos;  // Inserting the element at the tail, index: sizeList
    listSize++;     // Increase the size of the List by one

}

void objPosArrayList::removeHead()
{
    if(listSize == 0)
    {
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
    return aList[index];
}