#include<iostream>
using namespace std;

int createNumberUsingDigits(int digits){
    int num =0;
    for(int i=0; i<digits; i++){
        cout<<"Enter digit: ";
        int digit;
        cin >> digit;
        num = num*10+digit;
        cout <<"Number created so far: "<<num<<endl;
    }
    return num;
}

int main(){
    int digits;
    cout <<"Enter the number of digits: ";
    cin >> digits;
    int num = createNumberUsingDigits(digits);
    cout << "The number is: "<<num<<endl;
    return 0;
}