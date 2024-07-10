#include<iostream>
using namespace std;

int fibonacci(int n){
    // base case
    if(n == 0 || n == 1) return n;
    // recursive call
    int ans = fibonacci(n-1)+fibonacci(n-2);
    return ans;
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "The"<<n<<"'th term of fibonacci series is: "<<fibonacci(n);
    return 0;
}