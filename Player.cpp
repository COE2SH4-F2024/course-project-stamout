#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef;
    food = thisFood;
    state = STOP;

    playerPosList = new objPosArrayList();

    objPos playerPos(thisGMRef->getBoardSizeX() / 2, thisGMRef->getBoardSizeY() / 2, '@');

    playerPosList->insertHead(playerPos);
}


Player::~Player()
{
    // delete any heap members here 
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos objPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();

    
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
            // This essentially converts the ASCII character input to a number 1-5 by subtracting
            // the zero character. For example, if we take input = '5', this is equivalent to
            // input = 53. So when we subtract it by zero, we are really subtracting it by 48 ('0' == 48).
            // So '5' - '0' = 53 - 48 = 5
            mainGameMechsRef->setSpeed(input - '0');
            break;
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

    objPosArrayList* foodPosList = food->getFoodPos();
    playerPosList->insertHead(head);

    // Must check self collision AFTER we've added the new head
    if (checkSelfCollision()) {
        // If we self collide, we want to both exit the game, and be in a lose game state
        // So we set both flags.
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();

        // This will technically cause the snake to increase in length, since we won't get to remove
        // the tail, but the new head will be on top of itself. So the user won't be able to tell.
        return;
    }

    bool found = false;
    for (int i = 0; i < foodPosList->getSize(); i++) {
        objPos currentPos = foodPosList->getElement(i);

        if (head.isPosEqual(&currentPos)) {
            // Increase score by 10 when we hit a special food
            if (currentPos.symbol == SPECIAL_FOOD_CHARACTER) {
                mainGameMechsRef->increaseScore(10);
            } else {
                mainGameMechsRef->incrementScore();
            }

            food->generateFood(*playerPosList);
            found = true;
            break;
        }
    }

    if (!found) {
        playerPosList->removeTail();
    }
}

bool Player::checkSelfCollision()
{
    // We don't change position in the stopped state, so we don't want to check our position since
    // our new head will be at the same position.
    if (state == STOP) {
        return false;
    }

    objPos head = playerPosList->getHeadElement();
    
    // Compare all player positions (starting after the head) to the head
    for (int i = 1; i < playerPosList->getSize(); i++) {
        objPos currentPos = playerPosList->getElement(i);
        if (head.isPosEqual(&currentPos)) {
            return true;
        }
    }

    return false;
}

// More methods to be added