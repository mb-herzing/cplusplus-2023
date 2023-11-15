#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>

using namespace std;

//  Sets the number of sides on the die.
const int dieSize = 4;
//  Sets the speed in which the flood increases.
const int floodSpeed = 2;
//  Set the goal to reach to escape the flood
const int goalLevel = 50;

class GameBoard {
private:
    int floodLevel;
    int playerLevel;
    int turnNumber;
public:
    //  Standard constructor for GameBoard
    GameBoard() {
        floodLevel = 0;
        playerLevel = 1;
        turnNumber = 1;
    }
    //  Returns the flood level
    int getFloodLevel() { return floodLevel; }
    //  Returns the player's level
    int getPlayerLevel() { return playerLevel; }
    //  Returns the turn number
    int getTurnNumber() { return turnNumber; }
    //  Increase the flood's level
    void increaseFloodLevel() {
        //  Let the player know the flood is rising
        cout << "The flood is rising!" << endl;
        //  Increment the flood accordingly
        floodLevel += floodSpeed; 
    }
    void incrementTurnNumber() { turnNumber++; }
    //  Update the player's level to whatever they rolled. May be positive or negative.
    void updatePlayerLevel(int change) { 
        //  If the player climbs up successfully...
        if (change > 0) {
            //  Output the player's climb in levels
            cout << "You climbed " << change << " levels!" << endl;
        }
        //  Else, if the player falls down...
        else {
            //  Output the player's fall in levels
            cout << "You fell " << -change << " levels!" << endl;
        }
        //  Update the player's level accordingly
        playerLevel += change;
    }
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
int rollDie() {
    //  Sleep for a second for different system time
    this_thread::sleep_for(chrono::seconds(1));
    //  Create a seed for the random number generator
    srand(time(NULL));
    //  Generate the dice roll
    int result = (rand() % dieSize) + 1;
    //  Print out the results
    cout << "You rolled a " << result << "!" << endl;
    //  Return the resulting number
    return result;
}

//  Function for rolling two dice. Uses the rollDie function.
int rollDice() {
    //  Create variables for each die result
    int die1 = 0, die2 = 0;
    //  Roll the results for the dice
    die1 = rollDie();
    die2 = rollDie();
    // Add the dice together for the result
    int result = die1 + die2;
    //  If the dice are the same number...
    if (die1 == die2) {
        //  Negate the resulting number
        result = -result;
    }
    //  Return the resulting roll
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
        //  Create a variable to store the player's choice
        int input;
        //  While the player is above the flood...
        while (board.playerAboveFlood() && board.getPlayerLevel() < goalLevel) {
            //  Output current turn number, flood level, and player level
            cout << "Turn " << board.getTurnNumber() << ": ";
            cout << "Flood Level: " << board.getFloodLevel() << " | ";
            cout << "Player Level: " << board.getPlayerLevel() << endl;
            //  Ask player to roll one die or two dice
            cout << "Type '1' to climb carefully or type '2' to climb hastily." << endl;
            cin >> input;
            //  Evaluate the player's choice
            switch (input) {
            case 1:
                board.updatePlayerLevel(rollDie());
                break;
            case 2:
                board.updatePlayerLevel(rollDice());
                break;
            default:
                break;
            }
            //  Increment the flood's level
            board.increaseFloodLevel();
            //  Increment the turn number
            board.incrementTurnNumber();
        }
        //  If the player makes it to the top...
        if (board.getPlayerLevel() >= goalLevel) {
            //  Congratulate the player on their daunting escape
            cout << endl << "Congratulations, " << player << "! You won the game!" << endl;
            cout << "You made it to the top in " << board.getTurnNumber() << " turns!" << endl;
            cout << "Can you get to the top faster? Try again some other time!" << endl;
        }
        //  Else if the player went into the flood...
        else if (board.getFloodLevel() >= board.getPlayerLevel()) {
            cout << endl << "You drowned in the flood, " << player << "..." << endl;
            cout << "You made it " << board.getTurnNumber() << " turns before drowning." << endl;
            cout << "Try again later!" << endl;
        }
        else {
            cout << "Something unexpected happened! Please try again later." << endl;
        }
    }

}