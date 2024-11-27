#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* foodPos);
        ~Player();

        objPosArrayList* getPlayerPos() const;   
        void updatePlayerDir();
        void movePlayer();


        // More methods to be added here
        bool checkSelfCollision();

    private:
        objPosArrayList* playerPosList;     
        Food* food;
        enum Dir state;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

};

#endif