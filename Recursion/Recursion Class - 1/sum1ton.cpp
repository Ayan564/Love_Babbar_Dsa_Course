#include<iostream>
using namespace std;

int getSum(int n){
    //base case
    if(n == 0) return 0;

    // recursive call and processing
    return n+getSum(n-1);
}

int main(){
    int n;
    cout <<"Enter the number: ";
    cin >> n;
    cout <<"The answer is "<<getSum(n);
    return 0;
}