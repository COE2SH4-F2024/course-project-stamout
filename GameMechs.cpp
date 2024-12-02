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

// Use constructor delegation to reduce code repetition here
// If unfamiliar, constructor delegation (the ": GameMechs()" syntax) makes
// a call to the other GameMechs() constructor before executing any other code.
GameMechs::GameMechs(int boardX, int boardY) : GameMechs()
{
    boardSizeX = boardX;
    boardSizeY = boardY;
}

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

void GameMechs::increaseScore(int x)
{
    score += x;
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
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
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

void GameMechs::setSpeed(int this_speed)
{
    speed = this_speed;
}

int GameMechs::getDelayAmount() const
{
    // Get the corresponding delay for our current speed
    // Keep in mind speed is one-indexed, i.e. it starts at 1 rather than 0.
    return this->gameSpeedDelays[speed - 1];
}