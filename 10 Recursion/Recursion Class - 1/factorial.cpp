#include<iostream>
using namespace std;

int factorial(int n){
    // base case (mandatory)
    if(n==0 || n==1){
        return 1;
    }
    // recursive call (mandatory) and processing (optional)
    return n*factorial(n-1);
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin >> n;
    int ans = factorial(n);
    cout<<"The answer is: "<<ans<<endl;
    return 0;
}