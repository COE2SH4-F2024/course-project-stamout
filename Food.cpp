#include "Food.h"
#include <stdlib.h>
#include <time.h>

Food::Food(int boardXMax, int boardYMax)
{
    xMax = boardXMax;
    yMax = boardYMax;
}

Food::~Food()
{
}

void Food::generateFood(objPosArrayList& blockOff)
{
    srand(time(NULL));
    objPos newPos(1 + rand() % (xMax - 1), 1 + rand() % (yMax - 1), 'o');

    

    while (true) {
        newPos = objPos(1 + rand() % (xMax - 1), 1 + rand() % (yMax - 1), 'o');

        for (int i = 0; i < blockOff.getSize(); i++) {
            objPos currentPos = blockOff.getElement(i);
            if (newPos.pos->x == currentPos.pos->x && newPos.pos->y == currentPos.pos->y) {
                continue;
            }
        }
        
        break;
    }
    
    foodPos = newPos;
}

objPos Food::getFoodPos() const
{
    return foodPos;
}