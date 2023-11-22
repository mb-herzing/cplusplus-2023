#include <iostream>
#include <time.h>

using namespace std;

class GuessingGame {
protected:
    int mysteryNumber;
    int upperNumber;
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
    //  Gets the upper limit for the mystery number
    int getUpperNumber() { return upperNumber; }
    //  Sets the upper limit for the mystery number
    void setUpperNumber(int un) { upperNumber = un; }

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

    //  Provide a range for the player to guess between and the number of guesses they have left
    void printGameInfo() {
        cout << "Guess a number between 1 and " << getUpperNumber() << "!\n";
        cout << "Number of guesses left: " << getNumberOfGuesses() << "\n > ";
    }

    //  Basic constructor for the GuessingGame class.
    GuessingGame() { }

    //  Overloaded constructor for the GuessingGame class.
    GuessingGame(int mn, int ng) {
        //  Set the variables as they're entered
        setUpperNumber(mn);
        setMysteryNumber(generateRandomNumber(getUpperNumber()));
        setNumberOfGuesses(ng);
    }
};

class EasyGame : public GuessingGame {
public:
    //  Number between 1 and 20(?), 5 guesses(?)
    EasyGame() : GuessingGame(20, 5) {}
};

class MediumGame : public GuessingGame {
public:
    //  Number between 1 and 100(?), 8 guesses(?)
    MediumGame() : GuessingGame(100, 8) {}
};

class HardGame : public GuessingGame {
public:
    //  Number between 1 and 500(?), 10 guesses(?)
    HardGame() : GuessingGame(500, 10) {}
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
    bool numberGuessed = false;
    string guessInput;
    //  While the player hasn't guessed the number and they still have guesses...
    do {
        //  Print the game information
        game.printGameInfo();
        //  Get player's guess
        cin >> guessInput;
        //  If the number is guessed correctly...
        if (stoi(guessInput) == game.getMysteryNumber()) {
            //  Set the respective boolean value to true
            numberGuessed = true;
            //  Decrease the number of guesses anyway, since it still counts as a valid guess
            game.decrementGuesses();
            //  Exit the loop, as the player has won!
            break;
        }
        //  Else if the guess is higher than the number, but not above the max...
        else if (stoi(guessInput) > game.getMysteryNumber()
                && stoi(guessInput) <= game.getUpperNumber()) {
            //  Inform the player the guess was too high
            cout << "Your guess was too high!\n";
            //  Decrease the number of guesses
            game.decrementGuesses();
        }
        //  Else if the guess is lower than the number, but not below the min...
        else if (stoi(guessInput) < game.getMysteryNumber()
                && stoi(guessInput) >= 1) {
            //  Inform the player the guess was too low
            cout << "Your guess was too low!\n";
            //  Decrease the number of guesses
            game.decrementGuesses();
        }
        //  Else, the player likely didn't enter the number right...
        else {
            //  Inform the player that their guess isn't valid
            cout << "Guess wasn't within range! Please try again.";
            //  Do not decrease the number of guesses, since it wasn't a valid guess
        }
        //  Add an extra space between each section for better readability
        cout << endl;
    }
    while (game.getNumberOfGuesses() > 0 && !numberGuessed);
    //  Once the game ends, check if the player guessed correctly first
    if (numberGuessed) {
        //  If they did, congratulate them and show statistics
        cout << "Congratulations! You guessed the number!\n";
        cout << "You had " << game.getNumberOfGuesses() << " guesses remaining!\n";
        cout << "Thank you for playing!";
    }
    //  Otherwise, the player probably ran out of guesses...
    else if (game.getNumberOfGuesses() <= 0) {
        cout << "Sorry, you didn't guess the number...\n";
        cout << "The mystery number was " << game.getMysteryNumber() << ".\n";
        cout << "Better luck next time!";
    }
    return 0;
}