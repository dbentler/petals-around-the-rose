// Darren Bentler, 25 March 2021

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
// Sleep function so the console game is a bit smoother. Has support for Windows and Unix-based systems.
#ifdef _WIN32
    #include <windows.h>

    void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>
    
    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif

using namespace std;

// Dice object
class Dice {
    public:
    // Gets dice value
    int roll(){
        return 1 + (rand() % 6);
    }

    int value = roll();
};

class Player {
    public:
    int streak;
    int correctRolls;
    int rollCount;
    bool potentate = false;

    int streakUp(int& streak){
        return streak++;
    }
    int correctUp(int& correctRolls){
        return correctRolls++;
    }
    int rollUp(int& rollNumber){
        return rollCount++;
    }
    int resetStreak(int& streak){
        return streak = 0;
    }
    int penalty(int& correctRolls){
        return correctRolls--;
    }

    void printInfo(){ // Your Streak: # | Correct Rolls: # | Number of Rolls: # | Potentate: bool
        cout << "Your Streak: " << streak << " | Correct Rolls: " << correctRolls << " | Number of Rolls: " << rollCount << " | Potentate: "<< potentate << endl;
    }
};

// Visualizes dice. Very important.
void diceVisual(const vector<int>& rolls){
    for(auto val : rolls){
        switch(val){
            case 1:
                cout << "=======" << endl;
                cout << "|     |" << endl;
                cout << "|  *  |" << endl;
                cout << "|     |" << endl;
                cout << "=======" << endl;
                cout << "" << endl;
                break;
            case 2:
                cout << "=======" << endl;
                cout << "|*    |" << endl;
                cout << "|     |" << endl;
                cout << "|    *|" << endl;
                cout << "=======" << endl;
                cout << "" << endl;
                break;
            case 3:     
                cout << "=======" << endl;
                cout << "|*    |" << endl;
                cout << "|  *  |" << endl;
                cout << "|    *|" << endl;
                cout << "=======" << endl;
                cout << "" << endl;
                break;
            case 4:
                cout << "=======" << endl;
                cout << "|*   *|" << endl;
                cout << "|     |" << endl;
                cout << "|*   *|" << endl;
                cout << "=======" << endl;
                cout << "" << endl;
                break;
            case 5:    
                cout << "=======" << endl;
                cout << "|*   *|" << endl;
                cout << "|  *  |" << endl;
                cout << "|*   *|" << endl;
                cout << "=======" << endl;
                cout << "" << endl;
                break;
            case 6:
                cout << "=======" << endl;
                cout << "|*   *|" << endl;
                cout << "|*   *|" << endl;
                cout << "|*   *|" << endl;
                cout << "=======" << endl;
                cout << "" << endl;
                break;                                          
        }
    }
}

// Rolls the dice values into a vector. Returns the vector.
vector<int> roll(vector<int>& yourRolls){
    vector<int> newRoll;
    for(int i = 0; i < 5; i++){
        Dice die;
        newRoll.push_back(die.roll());
    }
    return newRoll;
}

// Returns the score for the current die. If you're looking at this you're cheating.
int calculateResult(const vector<int>& rolls){
    int result = 0;
    for(auto value : rolls){
        if(value % 2 == 1 && value != 1){
            result = result + (value - 1);
        }
    }
    return result;
}

void title(){
    cout << "##############################" << endl;
    cout << "#                            #" << endl;
    cout << "#   PETALS AROUND THE ROSE   #" << endl;
    cout << "#                            #" << endl;
    cout << "##############################" << endl;    
}
void rules(){
    cout << "#////////////////////////////#" << endl;
    cout << "#           RULES            #" << endl;
    cout << "#                            #" << endl;
    cout << "# 1) The name of the Game is #" << endl;
    cout << "#         important.         #" << endl;
    cout << "#                            #" << endl;
    cout << "# 2)   Five dice will be     #" << endl;
    cout << "#           rolled.          #" << endl;
    cout << "#                            #" << endl;
    cout << "# 3) The score will always   #" << endl;
    cout << "#     be zero or an even     #" << endl;
    cout << "#           number.          #" << endl;
    cout << "#                            #" << endl;
    cout << "#     These are the only     #" << endl;
    cout << "#      rules I can tell      #" << endl;
    cout << "#            you.            #" << endl;
    cout << "#                            #" << endl;
    cout << "#////////////////////////////#" << endl;
}

void drawRose(){
    cout << "" << endl;
    cout << "               _,--._.-," << endl;
    cout << "             /\_r-,\_ )" << endl;
    cout << "            .-.) _;='_/ (.;" << endl;
    cout << "            \ \'     \/S )" << endl;
    cout << "            L.'-. _.'|-'" << endl;
    cout << "           <_`-'\'_.'/" << endl;
    cout << "          `'-._( \'" << endl; // Rose created by Shanaka Dias
    cout << "            ___   \\,      ___" << endl;
    cout << "            \ .'-. \\   .-'_. /" << endl;
    cout << "             '._' '.\\/.-'_.'" << endl;
    cout << "                '--``\('--'" << endl;
    cout << "                      \\" << endl;
    cout << "                      `\\," << endl;
    cout << "                        \|" << endl;
    cout << "" << endl;
}

void help(){
    cout << "To begin playing, type 'y'. If you wish to exit, type 'n'" << endl;
}

void instructions(){
    cout << "Your goal is simple:" << endl;
    cout << "Find out how the computer calculates the score." << endl;
    cout << "Once you reach a streak of 10, you officially become a 'Potentate of the Rose'." << endl;
}

// Gameplay!
void play(){
    Player player;
    player.streak = 0;
    player.correctRolls = 0;
    player.rollCount = 0;
    
    while(true){
        int guess;

        cout << "################################################" << endl;
        vector<int> currentRolls;
        currentRolls = roll(currentRolls);
        int score = calculateResult(currentRolls);
        diceVisual(currentRolls);
        cout << "################################################" << endl;

        player.printInfo();
        cout << "Enter your guess. You can stop playing at any time by entering '-1' as your guess." << endl;
        
        cout << "Your Guess: ";
        if(cin >> guess){
            if(guess == score){
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                cout << "Correct! The answer was " << score << "." << endl;
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                sleep(1500);
                player.streakUp(player.streak);
                if(player.streak == 10){ // Cutscene. Or as close as I can get to one via terminal...
                    player.potentate = true;
                    drawRose();
                    sleep(2500);
                    cout << "Congratulations, you are officially a Potentate of the Rose!" << endl;
                    sleep(1500);
                    cout << "As a Potentate, you must never reveal the secret of the game." << endl;
                    sleep(1500);
                    cout << "You must be cruel and heartless to whoever you show the game to, only telling them the following:" << endl;
                    rules();
                    sleep(3000);
                    cout << "Shall we continue playing?" << endl;
                    sleep(1500);
                }
                player.correctUp(player.correctRolls);
                player.rollUp(player.rollCount);
            }
            if (guess < 0){
                cout << "Exiting..." << endl;
                break;
            }
            if(guess != score){
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                cout << "Incorrect. The correct answer is " << score << "." << endl;
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                sleep(1500);
                player.resetStreak(player.streak);
                player.rollUp(player.rollCount);
            }
        } else {
            cin.clear();
            cin.ignore();
            cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << "Please enter a whole number as your guess. You have been penalized. Rerolling..." << endl;
            cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            sleep(1000);
            player.penalty(player.correctRolls);
            player.resetStreak(player.streak);
        }
    }    
}

int main(){
    srand(time(NULL)); // Seed setter, or else rand() will return the same value.
    
    // startup functions
    title();
    rules();
    instructions();
    cout << "-----------------------" << endl;
    help();

    string command;
    
    // Main "menu"
    while(true){
        cout << "Enter your command (y/n): ";
        if(cin >> command){
            if(command == "y"){
                play();
                break;
            } else if(command == "n"){
                cout << "Exiting..." << endl;
                break;
            } else {
                cout << "Please enter a valid command!" << endl;
            }
        } else {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid command!" << endl;
        }
    }
    return 0;
}