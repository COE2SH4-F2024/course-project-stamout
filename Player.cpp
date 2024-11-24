#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    state = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    playerPos.pos->y =  mainGameMechsRef->getBoardSizeY() / 2;
    playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
    //no keyword "new" in the constructor 
    //leave the destrcutor empty for now 
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    //mainGameMechsRef->clearInput();

    
        // PPA3 input processing logic 

    switch(input)
    {       
        case 'W':              
        case 'w':
            if(state != UP && state != DOWN)
            {
                state = UP;
            }
            break;
        case 'A':
        case 'a':
            if(state != LEFT && state != RIGHT)
            {
                state = LEFT;
            }
            break;
        case 'S':
        case 's': 
            if(state != UP && state != DOWN)
            {
                state = DOWN;
            }
            break;
        case 'D':
        case 'd':
            if(state != LEFT && state != RIGHT)
            {
                state = RIGHT;
            }
            break;  
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            // Nice trick, but can be a little unclear
            mainGameMechsRef->setSpeed(input - '0');
            break;
        // case '=':
        //     if(mainGameMechsRef->getSpeed() >= 1 && mainGameMechsRef->getSpeed() < 5)
        //     {
        //         mainGameMechsRef->increaseSpeed();
        //     }
        //     break;
        // case '-':
        //     if(mainGameMechsRef->getSpeed() > 1 && mainGameMechsRef->getSpeed() <= 5)
        //     {
        //         mainGameMechsRef->decreaseSpeed();
        //     }
        //     break;
    }        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(state)
    {
        case LEFT:  // exit
            playerPos.pos->x--;
            if (playerPos.pos->x == 0)
            {
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX()-1;
            }
            break;
        case RIGHT:
            playerPos.pos->x++;
            if (playerPos.pos->x == mainGameMechsRef->getBoardSizeX())
            {
                playerPos.pos->x = 1;
            }
            break;
        case UP:
            playerPos.pos->y--;
            if (playerPos.pos->y == 0)
            {
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 1;
            }
            break;
        case DOWN:
            playerPos.pos->y++;
            if (playerPos.pos->y == mainGameMechsRef->getBoardSizeY())
            {
                playerPos.pos->y = 1;
            }
            break;
        case STOP:
        default:
            break;

    }
}

// More methods to be added