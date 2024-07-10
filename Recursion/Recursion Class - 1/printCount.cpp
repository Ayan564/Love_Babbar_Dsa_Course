#include<iostream>
using namespace std;

void printn(int n){
    // base case (mandatory)
    if(n==1){
        cout << 1 << " ";
        return;
    }
    // recursive call (mandatory)
    printn(n-1);
    // processing (optional)
    cout << n << " ";
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin >> n;
    printn(n);
    return 0;
}