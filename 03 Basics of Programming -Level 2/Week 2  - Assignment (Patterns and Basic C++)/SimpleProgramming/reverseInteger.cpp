#include<iostream>
#include<limits.h>
using namespace std;

int reverseInteger(int n){
    int ans =0;
    bool isNegetive = false;
    if(n <= INT_MIN){
        return 0;
    }
    if(isNegetive){
        n = -n;
    }
    while(n){
        if(ans > INT_MAX/10){
            return 0;
        }
        int digit = n % 10;
        ans = ans *10 + digit;
        n = n /10;
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int ans = reverseInteger(n);
    cout << "The reverse number is: "<<ans<<endl;
    return 0;
}