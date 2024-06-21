#include<iostream>
#include<cmath>
using namespace std;

int isPrime1(int num){
    if (num <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    if (num == 2) {
        return 1; // 2 is a prime number
    }
    for(int i=2; i<num; i++){
        if(num % i == 0){return 0;}
    }
    return 1;
}

bool isPrime2(int num) {
    if (num <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    if (num == 2) {
        return 1; // 2 is a prime number
    }
    // Check divisibility from 2 up to the square root of num
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // If num is divisible by i, it's not prime
        }
    }
    return 1; // If num is not divisible by any numbers, it's prime
}

int main(){
    int answer = isPrime2(577);
    if(answer == 1){
        cout<<"The No is a prime No."<<endl;
    }else{
        cout<<"The No is not a prime No."<<endl;
    }
    return 0;
}