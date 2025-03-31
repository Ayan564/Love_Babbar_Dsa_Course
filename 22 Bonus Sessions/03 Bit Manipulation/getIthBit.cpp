#include<iostream>
using namespace std;

void getIthBit(int n, int i){
    if(n & (1<<i)){
        cout << "The " << i << "th bit of " << n << " is set" << endl;
    }else{
        cout << "The " << i << "th bit of " << n << " is not set" << endl;
    }
}

int main(){
    int n, i;
    cout << "Enter a number: ";
    cin>>n;
    cout << "Enter the bit position: ";
    cin>>i;
    getIthBit(n, i);

    return 0;
}