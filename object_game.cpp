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
    void setNumberOfGuesses(int nt) { numberOfGuesses = nt; }
    //  Generates a random number. Each subclass must have its own version of this method.
    int generateRandomNumber();
    //  Decrease the number of guesses remaining whenever the player guesses
    void decrementGuesses() { numberOfGuesses--; }
};

class EasyGame : public GuessingGame {
    //  Number between 1 and 20(?), 5 guesses(?)
};

class MediumGame : public GuessingGame {
    //  Number between 1 and 100(?), 10 guesses(?)
};

class HardGame : public GuessingGame {
    //  Number between 1 and 500(?), 15 guesses(?)
};

int main() {
    return 0;
}