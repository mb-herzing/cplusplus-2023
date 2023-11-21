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
    //  Constructor for the GuessingGame class. Each subclass will have its own version.
    GuessingGame(int mn, int ng) {
        cout << "Base class working!";
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
    //  Number between 1 and 100(?), 10 guesses(?)
};

class HardGame : public GuessingGame {
public:
    //  Number between 1 and 500(?), 15 guesses(?)
};

int main() {
    //  Testing
    EasyGame easy;
    return 0;
}