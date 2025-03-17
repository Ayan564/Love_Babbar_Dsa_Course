#include<iostream>
using namespace std;

void checkPowerOfTwo(int n){
    if(n==0){
        cout<<"No";
        return;
    }
    if((n&(n-1))==0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin>>n;
    checkPowerOfTwo(n);
    return 0;
}