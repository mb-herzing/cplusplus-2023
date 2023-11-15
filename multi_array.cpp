#include <iostream>
#include <vector>

using namespace std;

int main() {
    //  Creating the grid, a multidimensional vector array
    vector<vector<int>> grid(3, vector<int>(3));
    //  Preparing input value
    int input = 0;

    //  For every column in the array...
    for (int i = 0; i < grid.size(); i++) {
        //  ...and for every row...
        for (int j = 0; j < grid[i].size(); j++) {
            //  Prompt the user to enter a number
            cout << "Please enter a number:" << endl;
            //  Obtain the number the user entered
            cin >> input;
            //  Insert the number in the available "cell"
            grid[i][j] = input;
        }
    }

    //  Once the user has filled in the grid, display the grid in all its glory
    cout << "Here's the numbers you entered in the grid:" << endl;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            //  Output the value in the grid followed by a space
            cout << grid[i][j] << " ";
        }
        //  Start a new line for the next row
        cout << endl;
    }
}