#include<iostream>
using namespace std;

int main(){
    int number,count=0;
    cin >> number;
    while(number){
        if(number&1){
            count++;
        }
        number >>= 1;
    }
    cout<<"Total no of setbits = "<< count;
    return 0;
}