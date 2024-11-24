#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    speed = 1;
    delayAmount = 500000; // New Frame every 0.5 sec

    boardSizeX = 29;
    boardSizeY = 14;

    food.setObjPos(10,10,'o');
    //intialize the food object outside the gameboard
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    speed = 1;
    delayAmount = 500000; // New Frame every 0.5 sec

    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //Nothing on the heap
    //Destructor can stay empty for now 
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag; //
}
    
void GameMechs::collectAsyncInput()
{
    if (MacUILib_hasChar() != 0)
    {
        input = MacUILib_getChar();
    }
    
    if(input == '\e')
    {
        setExitTrue();
    }
}

char GameMechs::getInput() 
{
    return input; 
}

int GameMechs::getScore() const
{
    //return score; //
}

void GameMechs::incrementScore()
{
    //score++; //
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here
int GameMechs::getSpeed()
{
    return speed;
}
// void GameMechs::increaseSpeed()
// {
//     speed++;
// }
// void GameMechs::decreaseSpeed()
// {
//     speed--;
// }
int GameMechs::setSpeed(int this_speed)
{
    speed = this_speed;
}
int GameMechs::getDelayAmount()
{
    return delayAmount;
}
void GameMechs::setDelayAmount(int this_amount)
{
    delayAmount = this_amount;
}

void GameMechs::generateFood(objPos blockOff)
{
    //You only need to block off the player position for now
    //Easier for now,upgrade this in t=iteration 3.
}

objPos GameMechs::getFoodPos() const
{
    return food;
}