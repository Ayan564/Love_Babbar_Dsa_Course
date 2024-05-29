#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    if (n == 2) {
        return 1; // 2 is a prime number
    }
    // Check divisibility from 2 up to the square root of num
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0; // If num is divisible by i, it's not prime
        }
    }
    return 1; // If num is not divisible by any numbers, it's prime
}

void printAllPrime(int n){
    cout <<"The prime numbers are: ";
    for(int i=1; i<=n; i++){
        if(isPrime(i)){
            cout << i <<" ";
        }
    }
}

int main(){
    int n;
    cout << "Enter the range's upper value: ";
    cin >> n;
    printAllPrime(n);
    return 0;
}