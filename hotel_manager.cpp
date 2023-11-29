#include <vector>
#include <iostream>

using namespace std;

//  Tenant class - Holds information about hotel customers, also known as tenants.
class Tenant {
private:
    string name;        //  The name of the tenant or the "head" of the group.
    int roomNumber;     //  The room number the tenant is occupying.
    int duration;       //  How long the tenant is staying in days.
    string comments;    //  Any comments regarding this tenant.
public:
    //  Setter functions
    void setName(string n) { name = n; }
    void setRoomNumber(int r) { roomNumber = r; }
    void setDuration(int d) { duration = d; }
    void setComments(string c) {comments = c; }
    //  Getter functions
    string getName() { return name; }
    int getRoomNumber() { return roomNumber; }
    int getDuration() { return duration; }
    string getComments() { return comments; }
    //  Outputs a formatted list of all tenant information.
    void outputTenantInfo() {
        cout << "--------------------------------------------------------------------\n";
        cout << "Tenant Name: " << getName() << endl;
        cout << "Room Number: " << getRoomNumber() << endl;
        cout << "Stay Duration (in days): " << getDuration() << endl;
        //  If comments are empty, print "N/A", otherwise print the comments. 
        cout << "Comments: " << (getComments().empty() ? "N/A" : getComments()) << endl;
        cout << "--------------------------------------------------------------------\n";
    }
    //  Default constructor - Name, room number, and stay duration required.
    Tenant(string n, int r, int d) {
        setName(n);
        setRoomNumber(r);
        setDuration(d);
    }
    //  Optional constructor - Name, room number, stay duration, and comments.
    Tenant(string n, int r, int d, string c) {
        setName(n);
        setRoomNumber(r);
        setDuration(d);
        setComments(c);
    }
};

//  Hotel class - Holds all the Tenant objects, allows for more information as well.
class Hotel {
    //  Developer note: use vector.at(#) instead of vector[#]
private:
    vector<Tenant> tenants; //  Vector of Tenants, will store info for all tenants.
public:
    //  Adds a Tenant to the Tenants vector
    void addTenant(Tenant newTenant) { tenants.push_back(newTenant); }
    //  Checks if a room number is vacant, i.e. not currently occupied by another tenant.
    bool isVacant(int roomNumber) {
        bool roomVacant = true;
        for (Tenant tenant : tenants) {
            if(tenant.getRoomNumber() == roomNumber) {
                roomVacant = false;
                break;
            }
        return roomVacant;
        }
    }
};

//  Main class - starts the Hotel Manager program.
int main() {
    //  Initialize classes and variables
    Hotel hotel;
    string input = "";
    //  Output standard greeting
    cout << "Welcome to the Hotel Manager!\n";
    cout << "Please enter any of the following commands:\n";
    cout << "view - Lists all rooms occupied by tenants and tenant information.\n";
    cout << "add - Enter a new tenant into the system.\n";
    cout << "quit - Exits the program.\n";
    //  Perform the following...
    do {
        //  Retrieve the user's input
        cin >> input;
    }
    //  While the input does not match "quit"
    while (input.compare("quit") != 0);
    //  Since this runs after the user quits, bid the user farewell
    cout << "Program exited. Have a good day!";
    //  Return a standard exit code, code 0
    return 0;
}