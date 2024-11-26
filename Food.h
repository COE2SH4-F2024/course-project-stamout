#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

class Food
{
    public:
        Food(int xMax, int yMax);
        ~Food();

        void generateFood(objPosArrayList& blockOff);
        objPos getFoodPos() const;

    private:
        objPos foodPos;
        int xMax;
        int yMax;
};

#endif


