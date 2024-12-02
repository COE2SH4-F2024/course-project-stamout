#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; //Global pointer meant to instantiate a player object on the heap. 
GameMechs *myGM;
Food *food;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while (myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic(); 
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs();
    food = new Food(myGM->getBoardSizeX(), myGM->getBoardSizeY());
    
    myPlayer = new Player(myGM, food);
    food->generateFood(*myPlayer->getPlayerPos());
}

void GetInput(void)
{
    myGM->collectAsyncInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPosArrayList* playerPosList = myPlayer->getPlayerPos();
    objPos playerHead = playerPosList->getHeadElement();

    //objPos foodPos = myGM->getFoodPos();
    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    MacUILib_printf("Player [x , y, sym] = [%d, %d, %c]\n", playerHead.pos->x, playerHead.pos->y, playerHead.symbol);

   for(int i = 0; i <= boardY; i++) //y-direction
   {
        for(int j = 0; j <= boardX; j++) //x direction
        {
            bool found = false;
            for (int k = 0; k < playerPosList->getSize(); k++) {
                objPos currentPos = playerPosList->getElement(k);
                if (i == currentPos.pos->y && j == currentPos.pos->x) {
                    MacUILib_printf("%c", currentPos.symbol);
                    found = true;
                    break;
                }
            }
            
            for (int k = 0; k < food->getFoodPos()->getSize(); k++) {
                objPos currentPos = food->getFoodPos()->getElement(k);
                if (i == currentPos.pos->y && j == currentPos.pos->x) {
                    MacUILib_printf("%c", currentPos.symbol);
                    found = true;
                    break;
                }
            }

            if (found) {
                continue;
            }
            // Border
            else if(i == 0 || j == 0 || i == boardY || j == boardX)
            {
                MacUILib_printf("%c", '#');
            } 
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("%c", '\n');
   } 
    MacUILib_printf("\n");
    MacUILib_printf("\nCurrent Game Speed: %dx\n", myGM->getSpeed());
    MacUILib_printf("\nScore: %d\n", myGM->getScore());

    // Lose flag is set if the snake self-collides (meaning a game loss state),
    // exit flag is set if the player exits the game (esc button)
    if (myGM->getExitFlagStatus())
    {
        if (myGM->getLoseFlagStatus()) {
            MacUILib_printf("Game over: You lose\n");
        } else {
            MacUILib_printf("Game ended\n");
        }
    }

    MacUILib_printf("\n=============================================================\n");
    MacUILib_printf("Game Speed Adjustment Instructions:\n");
    MacUILib_printf("-------------------------------------------------------------\n");
    MacUILib_printf("Enter '1' to 1x your Normal Game Speed (0.50 seconds delay).\n");
    MacUILib_printf("Enter '2' to 2x your Normal Game Speed (0.35 seconds delay).\n");
    MacUILib_printf("Enter '3' to 3x your Normal Game Speed (0.20 seconds delay).\n");
    MacUILib_printf("Enter '4' to 4x your Normal Game Speed (0.10 seconds delay).\n");
    MacUILib_printf("Enter '5' to 5x your Normal Game Speed (0.01 seconds delay).");
    MacUILib_printf("\n=============================================================\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(myGM->getDelayAmount());
}


void CleanUp(void)
{
    delete myPlayer;
    delete myGM;
    delete food;

    MacUILib_uninit();
}
