#include <iostream>
#include <limits> // Needed for numeric_limits
using namespace std;

int main() {
    int num;
    
    cout << "Enter an integer: ";
    cin >> num;

    if (cin.fail()) {
        cout << "Invalid input. Please enter an integer." << endl;
        // Clear the fail state to allow further input
        cin.clear(); 
        // Discard any remaining characters in the input buffer
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    } else {
        cout << "Entered integer: " << num << endl;
    }

    return 0;
}

