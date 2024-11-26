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
}

// Use constructor delegating to reduce code repetition here
GameMechs::GameMechs(int boardX, int boardY) : GameMechs()
{
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
    return loseFlag;
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
    return score;
}

void GameMechs::incrementScore()
{
    score++;
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
int GameMechs::getSpeed() const
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

void GameMechs::setSpeed(int this_speed)
{
    speed = this_speed;
}

int GameMechs::getDelayAmount() const
{
    return this->gameSpeedDelays[speed - 1]; // speed is one-indexed
}