#include <iostream>
using namespace std;

int main() {
    int num;
    char ch;
    
    cout << "Enter a number: ";
    cin >> num;

    // Ignore the newline character in the buffer
    // cin.ignore();

    cout << "Enter a character: ";
    cin >> ch;

    cout << "Number: " << num << endl;
    cout << "Character: " << ch << endl;

    return 0;
}
