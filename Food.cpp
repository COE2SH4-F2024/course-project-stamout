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

    //Reomve all food objects from the gameboard everytime we want to generate new food positions after the snake collides with a food object.  
    for (int i = 0; i < numFood; i++) {
        foodBucket->removeTail();
    }
 
    for (int i = 0; i < numFood; i++) {
        char symbol = 'o';
        //if i equals the last food item in the object position array, then make symbol the special chracter (?) which gives player 10 extra points when they collide to it. 
        if (i == numFood - 1) {
            symbol = SPECIAL_FOOD_CHARACTER;
        }

        //Generate a random x and y position within the range excluding the border positions. 
        int randX = 1 + rand() % (xMax - 1);
        int randY = 1 + rand() % (yMax - 1);

        //Create an object for new position of the food item at a random x & y coord and with the symbol. 
        objPos newPos(randX, randY, symbol);

        while (true) {
            newPos = objPos(1 + rand() % (xMax - 1), 1 + rand() % (yMax - 1), symbol);

            // Check that we're not creating a food item on the snake
            bool found = false;

            for (int i = 0; i < blockOff.getSize(); i++) {
                objPos currentPos = blockOff.getElement(i);
                if (newPos.isPosEqual(&currentPos)) {
                    found = true;
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
                    found = true;
                    break;
                }
            }

            //if food item is created on the snake or food item, then run the while loop again to generate new x and y coord for food item.
            if (found) {
                continue;
            }
            
            break;
        }
        
        foodBucket->insertHead(newPos);
    }
}

//create an array object food items since we have multiple food items. 
objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}