#include<iostream>
using namespace std;

void evenOdd(int n){
    if(n & 1){
        cout << n << " is Odd" << endl;
    }else{
        cout << n << " is Even" << endl;
    }
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin>>n;
    evenOdd(n);
    return 0;
}