#include "Dice.h"

int main(){
    Player player;
    std::cout << player << std::endl;

    Dice dice;
    dice.visualizeRoll(dice.rolls);
}