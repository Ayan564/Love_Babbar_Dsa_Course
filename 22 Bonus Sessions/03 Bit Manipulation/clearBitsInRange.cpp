#include<iostream>
using namespace std;

void clearBitsInRange(int n, int i, int j){
    int a = -1<<(i+1);
    int b = ~(-1<<j);
    int mask = a|b;
    n = n&mask;
    cout<<n;
}

int main(){
    int n, i, j;
    cout << "Enter a number: ";
    cin>>n;
    cout << "Enter i: ";
    cin>>i;
    cout << "Enter j: ";
    cin>>j;
    clearBitsInRange(n, i, j);
    return 0;
}