#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

#define SPECIAL_FOOD_CHARACTER '?'

class Food
{
    public:
        Food(int xMax, int yMax);
        ~Food();

        void generateFood(objPosArrayList& blockOff);
        objPosArrayList* getFoodPos() const;

    private:
        objPosArrayList* foodBucket;

        int numFood;
        int xMax;
        int yMax;
};

#endif


