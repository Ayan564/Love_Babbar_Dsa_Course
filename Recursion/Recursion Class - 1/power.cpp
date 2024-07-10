#include<iostream>
using namespace std;

int power(int n,int pow){
    // base case
    if(pow == 1){
        return n;
    }
    // recursive call and processing
    return n*power(n,pow-1);
}

int main(){
    int n,pow;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter the power: ";
    cin >> pow;
    cout << "The ans is " << power(n,pow);
    return 0;
}