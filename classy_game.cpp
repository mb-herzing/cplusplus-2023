#include <iostream>
#include <time.h>

using namespace std;

//  Sets the number of sides on the die.
const int dieSize = 4;
//  Sets the speed in which the flood increases.
const int floodSpeed = 2;

class GameBoard {
private:
    int floodLevel;
    int playerLevel;
public:
    //  Standard constructor for GameBoard
    GameBoard() {
        floodLevel = 0;
        playerLevel = 1;
    }
    //  Returns the flood level
    int getFloodLevel() { return floodLevel; }
    //  Returns the player's level
    int getPlayerLevel() { return playerLevel; }
    //  Update the player's level to whatever they rolled. May be positive or negative.
    void updatePlayerLevel(int change) { playerLevel += change; }
    //  Increase the flood's level
    void increaseFloodLevel() { floodLevel += floodSpeed; }
    //  Check if the player is above the flood.
    bool playerAboveFlood() {
        //  If the player's level is above the flood's level...
        if (playerLevel > floodLevel) {
            //  Then this will return true
            return true;
        }
        //  Otherwise, this function will return false
        return false;
    }
};

//  Function for rolling one die. Used by itself when the player is climbing slowly.
int rollDie(int dieSize) {
    //  Create a seed for the random number generator
    srand(time(NULL));
    //  Generate the dice roll
    int result = (rand() % dieSize) + 1;
    //  Return the resulting number
    return result;
}

int main() {
    //  Print greeting and basic rules of the game
    cout << "Welcome to Flood Escape! The objective of this game is to make it ";
    cout << "to the end of the board while staying above the 'flood'!" << endl;
    cout << "You can choose to climb safely (roll 1 4-sided die) to ascend that number ";
    cout << "of spaces or climb hastily (roll 2 4-sided dice)." << endl;
    cout << "If you roll two of the same die while climbing hastily, you'll fall down ";
    cout << "that number of spaces, so choose wisely!" << endl;
    cout << endl << "Enter a name and press 'Enter' to begin!" << endl;

    string player;
    //  If the player enters a name...
    if (cin >> player) {
        //  Initialize the board upon start
        GameBoard board;
        //  While the player is above the flood...
        while (board.getPlayerLevel() > board.getFloodLevel()) {
            //  Create a variable to store the player's choice
            string input;
            //  Output current player and flood levels
        }
    }

}