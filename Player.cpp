#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    state = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList();

    objPos playerPos;
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    playerPos.pos->y =  mainGameMechsRef->getBoardSizeY() / 2;
    playerPos.symbol = '@';

    playerPosList->insertHead(playerPos);
}


Player::~Player()
{
    // delete any heap members here
    //no keyword "new" in the constructor 
    //leave the destrcutor empty for now 
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
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
    objPos oldHead = playerPosList->getHeadElement();
    objPos newHead(oldHead.pos->x, oldHead.pos->y, oldHead.symbol);

    switch(state)
    {
        case LEFT:  // exit
            newHead.pos->x--;
            if (newHead.pos->x == 0)
            {
                newHead.pos->x = mainGameMechsRef->getBoardSizeX()-1;
            }
            break;
        case RIGHT:
            newHead.pos->x++;
            if (newHead.pos->x == mainGameMechsRef->getBoardSizeX())
            {
                newHead.pos->x = 1;
            }
            break;
        case UP:
            newHead.pos->y--;
            if (newHead.pos->y == 0)
            {
                newHead.pos->y = mainGameMechsRef->getBoardSizeY() - 1;
            }
            break;
        case DOWN:
            newHead.pos->y++;
            if (newHead.pos->y == mainGameMechsRef->getBoardSizeY())
            {
                newHead.pos->y = 1;
            }
            break;
        case STOP:
        default:
            break;

    }

    playerPosList->insertHead(newHead);
    playerPosList->removeTail();
}

// More methods to be added