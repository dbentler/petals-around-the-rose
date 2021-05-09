#include "Player.h"

Player::Player(){
    streak = 0;
    correctRolls = 0;
    rollCount = 0;
    potenate = false;
}

Player::~Player(){};

std::string Player::isPotenate(){
    std::string text;
    if(potenate == false){
        return text = "False";
    } else {
        return text = "True";
    }
}

std::ostream& operator <<(std::ostream& os, Player& player){
    os << "Streak: " << player.streak << " | Correct Rolls: " << player.correctRolls << " | Number of Rolls: " << player.rollCount << " | Potenate: " << player.isPotenate() << std::endl;
    return os;
}