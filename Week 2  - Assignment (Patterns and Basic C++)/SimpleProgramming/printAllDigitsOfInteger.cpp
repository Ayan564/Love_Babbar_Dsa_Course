#include<iostream>
using namespace std;

void printAllDigits(int n){
    while(n){
        int ans = n%10;
        cout<<ans<<endl;
        n = n/10;
    }
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin >> n;
    printAllDigits(n);

    return 0;
}