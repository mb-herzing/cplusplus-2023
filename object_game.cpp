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
    cout << "by countless adventurers delving inside with hopes of peace and promises of riches.\n";
    cout << "Will you be the one to claim the foretold treasure and end this strife, ";
    cout << "or will you fall in battle like the rest?\n";

    //  Prompt player to continue
    cout << "Do you wish to continue? (y/n)\n";
    
    if (bool gameStarted = getYesNo()) {
        //  Boolean for class selection
        bool classSelected = false;
        //  Inform player of class options
        cout << "Adventurers of the dungeon often fall into three categories: the brave-hearted ";
        cout << "Fighters, the cunning Rangers, or the arcane Wizards.\n";
        cout << "Type (1) for Fighter, (2) for Ranger, or (3) for Wizard (sans parentheses).\n";
        string playerClass;
        do {
            //  Fetch player's choice in class
            cin >> playerClass;
            //  If the player selected Fighter...
            if (playerClass == "1") {
                //  Provide information about the Fighter
                cout << "Fighters are well known for having excellent armor than can deflect ";
                cout << "many attacks and have average damage, but their heavy armaments ";
                cout << "weigh them down considerably, resulting in less stamina.\n";
                cout << "Are you sure you'd like to play this class? (y/n)\n";
                if (classSelected = getYesNo()) {

                }
            }
            //  Else, if the player selected Ranger...
            else if (playerClass == "2") {
                //  Provide information about the Ranger
                cout << "Rangers are one of the most athletic people, with higher than average ";
                cout << "stamina and with decent light armor, but the bows and arrows they ";
                cout << "use are not very effective against dungeon enemies.\n";
                cout << "Are you sure you'd like to play this class? (y/n)\n";
                if (classSelected = getYesNo()) {
                    
                }
            }
            //  Else, if the player selected Wizard...
            else if (playerClass == "3") {
                //  Provide information about the Wizard
                cout << "Wizards are known for being able to manipulate magic, which is effective ";
                cout << "against many enemeies and they have average stamina, but properly ";
                cout << "casting magic means wearing very light armor, if any.\n";
                cout << "Are you sure you'd like to play this class? (y/n)\n";
                if (classSelected = getYesNo()) {

                }
            }
            // Else, the player may have entered an invalid option
            else {
                //  Inform player of invalid choice
                cout << "Invalid option entered! 1 for Fighter, 2 for Ranger, 3 for Wizard.\n";
            }
        }
        while (!classSelected);
        //  Return 0 (Exit Success)
        return 0;
    }
    else {
        //  Bid farewell to the player
        cout << "Perhaps another time. The dungeon will await you...";
        //  Return 1 (Forced Exit)
        return 1;
    }
    //  Return -1 (Exit Failure)
    return -1;
}