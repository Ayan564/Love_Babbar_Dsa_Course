#include<iostream>
using namespace std;

void countSetBit(int n){
    int count=0;
    while(n>0){
        n=n&(n-1);
        count++;
    }
    cout<< "Count of set bit: "<<count;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin>>n;
    countSetBit(n);
    return 0;
}