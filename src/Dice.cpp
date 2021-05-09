#include "Dice.h"

std::vector<int> Dice::rollDice(){
    std::vector<int> rolling;
    for (int i = 0; i < 5, i++;){
        int theRoll = 1 + (rand() % 6);
        rolling.push_back(theRoll);
    }
    return rolling;
}

void Dice::visualizeRoll(const std::vector<int>& rolls){
    int *rollNum;
    for(auto i : rolls){
        *rollNum = i;
        switch(*rollNum){
            case 1:
                std::cout << "=========" << std::endl;
                std::cout << "|       |" << std::endl;
                std::cout << "|   *   |" << std::endl;
                std::cout << "|       |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 2:
                std::cout << "=========" << std::endl;
                std::cout << "| *     |" << std::endl;
                std::cout << "|       |" << std::endl;
                std::cout << "|     * |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 3:
                std::cout << "=========" << std::endl;
                std::cout << "| *     |" << std::endl;
                std::cout << "|   *   |" << std::endl;
                std::cout << "|     * |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 4:
                std::cout << "=========" << std::endl;
                std::cout << "| *   * |" << std::endl;
                std::cout << "|       |" << std::endl;
                std::cout << "| *   * |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 5:
                std::cout << "=========" << std::endl;
                std::cout << "| *   * |" << std::endl;
                std::cout << "|   *   |" << std::endl;
                std::cout << "| *   * |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
            case 6:
                std::cout << "=========" << std::endl;
                std::cout << "| *   * |" << std::endl;
                std::cout << "| *   * |" << std::endl;
                std::cout << "| *   * |" << std::endl;
                std::cout << "=========" << std::endl;
                break;
        }
    }
}

int Dice::calculateScore(const std::vector<int>& rolls){
    int result = 0;
    for(auto value : rolls){
        if(value % 2 == 1 && value != 1){
            result = result + (value - 1);
        }
    }
    return result;
}

Dice::Dice(){
    srand(time(NULL));
    rolls = rollDice();
    score = calculateScore(rolls);
}