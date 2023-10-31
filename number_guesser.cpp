#include <iostream>
#include <time.h>
using namespace std;
int main() {
    //  Initializing variables
    int secretNumber;
    int guessNumber;

    //  Seed the random generator
    srand(time(NULL));

    //  Generate the secret number between 1 and 100
    secretNumber = (rand() % 100) + 1;

    //  Prompt the user to guess the number
    cout << "Guess a number between 1 and 100!\n";
    //  Allow user to enter their guess
    cin >> guessNumber;
    //  While the user hasn't guessed correctly...
    while (guessNumber != secretNumber) {
        //  If their guess is too low...
        if (guessNumber < secretNumber) {
            //  Inform user their guess is too low
            cout << "Too low! Please try again.\n";
        }
        // Else if their guess is too high...
        else if (guessNumber > secretNumber) {
            //  Inform user their guess is too high
            cout << "Too high! Please try again.\n";
        }
        // Allow user to enter a new guess
        cin >> guessNumber;
    }
    //  Once the user guesses correctly, inform them of their success
    cout << "You guessed the number! Thank you for playing!";
}