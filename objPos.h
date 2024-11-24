#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        //heap level position struct, instiate on the heap upon intialization , need deep copy applicable to copy constructpr and copy assignment operator and destructor  
        char symbol;

        objPos();   //intializes x, y posiiton and symbol associated with the x, y position 
        objPos(int xPos, int yPos, char sym);       //intializing object position with existing parameters 
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        objPos(const objPos &a); //Copy Constructor (2/4)
        objPos& operator=(const objPos &a); //Copy assignment operator (3/4)
        ~objPos(); // Destructor (4/4)
        
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif


