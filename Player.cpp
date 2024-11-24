#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef;
    food = thisFood;
    state = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList();

    objPos playerPos;
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    playerPos.symbol = '@';

    playerPosList->insertHead(playerPos);
}


Player::~Player()
{
    // delete any heap members here
    //no keyword "new" in the constructor 
    //leave the destrcutor empty for now 
    delete playerPosList;
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
    objPos head = playerPosList->getHeadElement();

    switch(state)
    {
        case LEFT:  // exit
            head.pos->x--;
            if (head.pos->x == 0)
            {
                head.pos->x = mainGameMechsRef->getBoardSizeX()-1;
            }
            break;
        case RIGHT:
            head.pos->x++;
            if (head.pos->x == mainGameMechsRef->getBoardSizeX())
            {
                head.pos->x = 1;
            }
            break;
        case UP:
            head.pos->y--;
            if (head.pos->y == 0)
            {
                head.pos->y = mainGameMechsRef->getBoardSizeY() - 1;
            }
            break;
        case DOWN:
            head.pos->y++;
            if (head.pos->y == mainGameMechsRef->getBoardSizeY())
            {
                head.pos->y = 1;
            }
            break;
        case STOP:
        default:
            break;

    }

    objPos foodPos = food->getFoodPos();

    playerPosList->insertHead(head);
    if (head.pos->x == foodPos.pos->x && head.pos->y == foodPos.pos->y) {
        food->generateFood(*playerPosList);
        mainGameMechsRef->incrementScore();
    } else {
        playerPosList->removeTail();
    }
}

// More methods to be added