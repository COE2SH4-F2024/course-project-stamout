#include "Food.h"
#include <stdlib.h>
#include <time.h>

Food::Food(int boardXMax, int boardYMax)
{
    xMax = boardXMax;
    yMax = boardYMax;
    numFood = 5;

    foodBucket = new objPosArrayList();
}

Food::~Food()
{
    delete foodBucket;
}

void Food::generateFood(objPosArrayList& blockOff)
{
    srand(time(NULL));

    for (int i = 0; i < numFood; i++) {
        foodBucket->removeTail();
    }

    for (int i = 0; i < numFood; i++) {
        char symbol = 'o';
        if (i == numFood - 1) {
            symbol = SPECIAL_FOOD_CHARACTER;
        }

        objPos newPos(1 + rand() % (xMax - 1), 1 + rand() % (yMax - 1), symbol);

        while (true) {
            newPos = objPos(1 + rand() % (xMax - 1), 1 + rand() % (yMax - 1), symbol);

            // Check that we're not creating a food item on the snake
            int found = 0;

            for (int i = 0; i < blockOff.getSize(); i++) {
                objPos currentPos = blockOff.getElement(i);
                if (newPos.isPosEqual(&currentPos)) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                continue;
            }

            // Check that we're not creating a food item on another food item
            for (int i = 0; i < foodBucket->getSize(); i++) {
                objPos currentPos = foodBucket->getElement(i);
                if (newPos.isPosEqual(&currentPos)) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                continue;
            }
            
            break;
        }
        
        foodBucket->insertHead(newPos);
    }
}

objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}