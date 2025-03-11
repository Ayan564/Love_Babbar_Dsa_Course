#include<iostream>
using namespace std;
int main(){
    int a = 5, b=6;
    // 1. Using in-built function
    swap(a,b);
    cout<<a<<" "<<b<<endl;

    // 2. Using temp variable
    int temp = a;
    a = b;
    b = temp;
    cout<<a<<" "<<b<<endl;

    // 3. Arithmatic method
    a = a + b;
    b = a - b;
    a = a - b;
    cout<<a<<" "<<b<<endl;

    // 4. Using XOR operator
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    cout<<a<<" "<<b<<endl;

    return 0;
}