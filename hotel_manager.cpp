#include <iostream>
#include <vector>

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
        cout << "Comments: " << (getComments().empty() ? "N/A" : getComments()) << endl;
        cout << "--------------------------------------------------------------------\n";
    }
};

//  Main class - starts the Hotel Manager program.
int main() {
    cout << "Program running!";
}