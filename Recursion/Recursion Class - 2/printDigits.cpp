#include<iostream>
using namespace std;

void printDigits(int num){
    if(num == 0){
        return;
    }
    int newNum = num /10;
    printDigits(newNum);
    cout << num%10<< " ";
}

int main(){
    int number = 389;
    printDigits(number);
    return 0;
}