#include<iostream>
#include<cmath>
using namespace std;

int binaryToDecimalMethod3(int n){
    int i=0, value=0;
    while(n > 0){
        int bit = n & 1;
        value += bit * pow(2,i++);
        n >>= 1;
    }
    return value;
}
int main(){
    string binaryStr;
    cout << "Enter the Binary Number: ";
    cin >> binaryStr;
    int binaryNumber = stoi(binaryStr, nullptr, 2);
    cout << "The Decimal of the number is "<< binaryToDecimalMethod3(binaryNumber);
    return 0;
}