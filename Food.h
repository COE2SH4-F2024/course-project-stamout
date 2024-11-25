#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"

class Food
{
    public:
        Food();
        ~Food();

        void generateFood(objPos blockOff, int xMax, int yMax);
        objPos getFoodPos() const;

    private:
        objPos foodPos;
};

#endif


