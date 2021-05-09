#ifndef DICE_H
#define DICE_H

#include "Player.h"

#include <ctime>
#include <vector>

class Dice{
    public:
        std::vector<int> rolls;
        int score;
    
    Dice();
    std::vector<int> rollDice();
    void visualizeRoll(const std::vector<int>& rolls);
    int calculateScore(const std::vector<int>& rolls);
};

#endif