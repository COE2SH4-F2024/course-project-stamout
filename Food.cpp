#include "Food.h"
#include <stdlib.h>
#include <time.h>

Food::Food()
{ 
}

Food::~Food()
{
}

void Food::generateFood(objPos blockOff, int xMax, int yMax)
{
    srand(time(NULL));
    objPos newPos(1 + rand() % (xMax - 1), 1 + rand() % (yMax - 1), 'o');

    while (newPos.isPosEqual(&blockOff)) {
        newPos = objPos(1 + rand() % (xMax - 1), 1 + rand() % (yMax - 1), 'o');
    }
    
    foodPos = newPos;
}

objPos Food::getFoodPos() const
{
    return foodPos;
}