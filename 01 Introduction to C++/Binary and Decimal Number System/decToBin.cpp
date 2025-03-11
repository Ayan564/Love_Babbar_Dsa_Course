#include<iostream>
#include<cmath>
using namespace std;

int decimalToBinaryMethod1(int n){
    int binaryNo = 0;
    int i = 0;
    while(n > 0){
        int bit = n % 2;
        binaryNo += bit * pow(10,i++);
        n = n / 2;
    }
    return binaryNo;
}

int decimalToBinaryMethod2(int n){
    int binaryNo = 0;
    int i = 0;
    while(n > 0){
        int bit = (n & 1);
        binaryNo += bit * pow(10,i++);
        n = n >> 1;
    }
    return binaryNo;
}


int main(){
    int n;
    cout<<"Enter the Decimal Number: ";
    cin>>n;
    int binary1 = decimalToBinaryMethod1(n);
    int binary2 = decimalToBinaryMethod2(n);
    cout << "The binary of the number is "<< binary1<< endl;
    cout << "The binary of the number is "<< binary2;

    return 0;
}