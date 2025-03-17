#include<iostream>
using namespace std;

void updateIthBit(int n, int i, int target){
    int mask = ~(1<<i);
    n = n & mask;
    mask = target<<i;
    n = n | mask;
    cout << "The number after updating the " << i << "th bit is: " << n << endl;
}

int main(){
    int n, i, target;
    cout << "Enter a number: ";
    cin>>n;
    cout << "Enter the bit position: ";
    cin>>i;
    cout << "Enter the target bit: ";
    cin>>target;
    updateIthBit(n, i, target);
    return 0;
}