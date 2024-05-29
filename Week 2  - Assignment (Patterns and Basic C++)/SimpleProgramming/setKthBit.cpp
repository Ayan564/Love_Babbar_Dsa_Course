#include<iostream>
using namespace std;

int setKthBit(int n, int k){
    int mask = 1 << k;
    int ans = n | mask;
    return ans;
}

int main(){
    int number,shift;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the shift: ";
    cin >> shift;
    int ans = setKthBit(number,shift);
    cout <<"After shifting the number is: "<<ans<<endl;
    return 0;
}