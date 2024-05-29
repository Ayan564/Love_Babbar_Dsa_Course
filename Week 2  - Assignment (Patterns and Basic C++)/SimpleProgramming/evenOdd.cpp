#include<iostream>
using namespace std;

int oddEven1(int num){
    if(num % 2 == 0){
        return 0;
    }else{
        return 1;
    }
}

int oddEven2(int num){
    if(num & 1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int n;
    cout <<"Enter the number: ";
    cin >> n;
    int answer = oddEven2(n);
    if(answer == 0){
        cout<<"The number is a even number."<<endl;
    }else{
        cout<<"The number is a odd number."<<endl;
    }
    return 0;
}