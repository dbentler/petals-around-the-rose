#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player{
    public:
        int streak;
        int correctRolls;
        int rollCount;
        bool potenate;
    
    Player();
    ~Player();
    
    friend std::ostream& operator <<(std::ostream& os, Player& player);

    std::string isPotenate();
};

std::ostream& operator <<(std::ostream& os, Player& player);

#endif
