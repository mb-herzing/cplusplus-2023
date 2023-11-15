#include <iostream>
#include <time.h>

using namespace std;

//  The Enemy class, which provides an opponent for the player to fight
class Enemy {
private:
    int health, atk, def;
    string name, weapon;
public:
    //  Upon generation, informs the player an enemy is here
    Enemy() {
        cout << "An enemy approaches!" << endl;
    }
    //  Sets the enemy's stats based on the input
    void setEnemy(int hp, int a, int d, string n, string wep) {
        health = hp;
        atk = a;
        def = d;
        name = n;
        weapon = wep;
    }
    //  Returns the health of the creature 
    int getHealth() { return health;  }
    int setHealth() { return health;  }

    /*  debug function
    string ListEnemy() {
        string info = name + " is attacking with " + weapon;
        return info;
    }
    */
   //   Upon deletion of an Enemy instance, signal they have been defeated
    ~Enemy() {
        cout << "The enemy has been defeated!" << endl;
    }
};

//  Function that generates an enemy based on preset stats
Enemy generateEnemy() {
    //  Arrays for aspects of enemies to choose from
    string  names[3]    = {"Goblin",    "Skeleton", "Slime"};
    int     health[3]   = {20,          15,         25} ;
    int     attack[3]   = {3,           2,          1};
    int     defense[3]  = {8,           12,         10};
    string  weapons[3]  = {"spear",     "scimitar", "psuedopod"};

    //  Generate a random number to determine which enemy to use
    srand(time(NULL));
    int index = rand() % 3;

    Enemy enemy;
    enemy.setEnemy(health[index], attack[index], defense[index], names[index], weapons[index]);
    return enemy;
}

/*  Rolls a single virtual die, generating a random number based on the number of sides
 *  the die has. See the rollDice function for rolling more than one die. 
 */
int rollDie(int sides) {
    //  Create a number to store the results of the die/dice roll(s)
    int result;
    //  Generate a random seed
    srand(time(NULL));
    //  Generate the random number based on the die's "shape"
    result = (rand() % sides) + 1;
    //  Return the results of the roll
    return result;
}

/*  Rolls multiple virtual dice, generating a random number based on the number of dice 
 *  and the number of sides each die has, respectively. See the rollDie function for 
 *  rolling one die only. 
 */
int rollDice(int num, int sides) {
    //  Create a number to store the results of the die/dice roll(s)
    int total = 0;
    //  For each die that's being rolled...
    for (int counter = 0; counter < num; counter++) {
        //  Generate a random seed
        srand(time(NULL));
        //  Generate the random number based on the die's "shape"
        total += (rand() % sides) + 1;
    }
    //  Return the resulting total of the rolls
    return total;
}

int main() {
    //  Greet the player upon startup
    cout << "Welcome, adventurer! Prepare for combat!" << endl;
    //  Initialize the basic variables for the player's character
    int playerHealth = 50, playerAttack = 4, playerDefense = 15, winStreak = 0;

    //  Create a random enemy for the player to fight
        Enemy opponent = generateEnemy();

    //  While the player is still alive...
    while (playerHealth > 0) {
        //  While the opponent is still alive...
        while (opponent.getHealth() > 0) {
            //  Let the player attack first
            cout << "What will you do? Type '1' to attack or '2' for healing!" << endl;
            //  Create variables to ensure proper choice selection 
            int selection;
            bool selectionMade = false;

            //  While the player hasn't made a proper selection yet...
            while (!selectionMade) {
                //  Take the player's input
                cin >> selection;
                //  Check whether the player's choice is a proper one
                switch (selection)
                {
                case 1:
                    //  Perform the attack!
                    cout << "Attack!!!" << endl;
                    //  Confirm a proper choice was made
                    selectionMade = true;
                    break;
                    
                case 2:
                    //  Heal the player!
                    cout << "Healing!" << endl;
                    //  Confirm that a proper choice was made
                    selectionMade = true;
                    break;
                
                default:
                    //  Inform the player that their selection was not recognized
                    cout << "Command not recognized!" << endl;
                    //  Confirm that a proper choice was not made
                    selectionMade = false;
                    //  Revert the selection to a neutral value
                    selection = 0;
                    break;
                }
            }
        }
    }
}