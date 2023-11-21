#include <iostream>

using namespace std;

//  Player superclass

//  Player Subclass - Fighter

//  Player Subclass - Ranger

//  Player Subclass - Wizard

//  Enemy superclass

//  Enemy Subclass = Goblin

//  Enemy Subclass - Skeleton

//  Enemy Subclass - Slime

//  Add a boss? Lich or something?

//  Method for providing player imput upon recieving a yes/no prompt
bool getYesNo() {
    bool answeredYes = false;
    string input;
    cin >> input;
    if (input == "y" || input == "Y") {
        answeredYes = true;
    }
    else if (input == "n" || input == "N") {
        answeredYes = false;
    }
    return answeredYes;
};

int main() {
    //  Provide some opening story to the player
    cout << "The terrible dungeon in the far edges of Sylvaestos has only been held back ";
    cout << "by countless adventurers delving inside with hopes of peace and promises of riches.";
    cout << endl << "Will you be the one to claim the foretold treasure and end this strife, ";
    cout << "or will you fall in battle like the rest?" << endl;

    //  Prompt player to continue
    cout << "Do you wish to continue? (y/n)" << endl;

    bool gameStarted = false;
    gameStarted = getYesNo();
    if (gameStarted) {
        //  Testing
        cout << "Game Started!";
    }
    else {
        //  Bid farewell to the player
        cout << "Perhaps another time. The dungeon will await you...";
        //  Return 1 (Player Exit)
        return 1;
    }
    //  Return 0 (Exit Success)
    return 0;
}