#include<iostream>
#include<cmath>
using namespace std;

int binaryToDecimalMethod1(int n){
    int i=0, value=0;
    while(n){
        int bit = (n%10);
        value = value + bit * pow(2,i++);
        n /= 10;
    }
    return value;
}
int main(){
    int n;
    cout<<"Enter the Binary Number: ";
    cin>>n;
    cout << "The Decimal of the number is "<< binaryToDecimalMethod1(n)<<endl;
    return 0;
}