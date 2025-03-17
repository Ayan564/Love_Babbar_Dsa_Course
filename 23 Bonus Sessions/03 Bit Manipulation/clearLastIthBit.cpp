#include<iostream>
using namespace std;

void clearLastIthBit(int n, int i){
    int mask = (-1<<i);
    n = n & mask;
    cout << "The number after clearing the " << i << "th bit is: " << n << endl;
}

int main(){
    int n, i;
    cout << "Enter a number: ";
    cin>>n;
    cout << "Enter the bit position: ";
    cin>>i;
    clearLastIthBit(n, i);

    return 0;
}