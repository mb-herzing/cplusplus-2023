#include <iostream>
#include <time.h>

using namespace std;

class GuessingGame {
protected:
    int mysteryNumber;
    int numberOfGuesses;
public:
    //  Gets the number the player is supposed to guess, A.K.A. the mystery number
    int getMysteryNumber() { return mysteryNumber; }
    //  Sets the mystery number
    void setMysteryNumber(int mn) { mysteryNumber = mn; }
    //  Gets the number of guesses left
    int getNumberOfGuesses() { return numberOfGuesses; }
    //  Sets the number of guesses the player has to guess the mystery number
    void setNumberOfGuesses(int ng) { numberOfGuesses = ng; }
    //  Generates a random number based on the maximum for the mystery number.
    int generateRandomNumber(int upper) {
        //  Create a variable to store the random number
        int random = 0;
        //  Seed the random number generator
        srand(time(NULL));
        //  Generate a random number between 1 and the "upper" number
        random = (rand() % upper) + 1;
        //  Return the newly generated number
        return random;
    }
    //  Decrease the number of guesses remaining whenever the player guesses
    void decrementGuesses() { numberOfGuesses--; }
    //  Basic constructor for the GuessingGame class.
    GuessingGame() { }
    //  Overloaded constructor for the GuessingGame class.
    GuessingGame(int mn, int ng) {
        cout << "Base class working!\n";
        setMysteryNumber(generateRandomNumber(mn));
        setNumberOfGuesses(ng);
    }
};

class EasyGame : public GuessingGame {
public:
    //  Number between 1 and 20(?), 5 guesses(?)
    EasyGame() : GuessingGame(20, 5) { cout << "Easy class working!"; }
};

class MediumGame : public GuessingGame {
public:
    //  Number between 1 and 100(?), 8 guesses(?)
    MediumGame() : GuessingGame(100, 8) { cout << "Medium class working!"; }
};

class HardGame : public GuessingGame {
public:
    //  Number between 1 and 500(?), 10 guesses(?)
    HardGame() : GuessingGame(500, 10) { cout << "Hard class working!"; }
};

int main() {
    //  Initialize variables and objects
    GuessingGame game;
    string input = "";
    bool validInput = false;
    //  Prompt player to select difficulty
    cout << "Type 1 for easy, 2 for medium, and 3 for hard\n > ";
    do {
        //  Grab player input
        cin >> input;
        //  Check if it's a valid input
        if (input == "1") {
            game = EasyGame();
            validInput = true;
        }
        else if (input == "2") {
            game = MediumGame();
            validInput = true;
        }
        else if (input == "3") {
            game = HardGame();
            validInput = true;
        }
        //  Otherwise, it is not valid
        else {
            cout << "Invalid input! Please try again.\n > ";
        }
    }
    while (!validInput);
    //  Once the difficulty is selected, begin the game!
    bool numberGuessed;
    while (!numberGuessed || game.getNumberOfGuesses() > 0) {
        
    }
    return 0;
}