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

bool isPrime3(int num) {
    if (num <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    if (num == 2 || num == 3) {
        return 1; // 2 and 3 are prime numbers
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return 0; // If num is divisible by 2 or 3, it's not prime
    }
    // Check divisibility by numbers up to the square root of num
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0; // If num is divisible by i or i+2, it's not prime
        }
    }
    return 1;
}


int main(){
    int n;
    cout <<"Enter the number: ";
    cin >> n;
    int answer = isPrime3(n);
    if(answer == 1){
        cout<<"The No is a prime No."<<endl;
    }else{
        cout<<"The No is not a prime No."<<endl;
    }
    return 0;
}