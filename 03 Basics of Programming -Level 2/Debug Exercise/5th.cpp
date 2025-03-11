#include<iostream>
using namespace std;

bool checkMember(int n){
    int f1 = 1, f2 = 1;
    if(n==0 || n==1){
        return true;
    }
    else{
        while(1){
            int temp = f1 + f2;
            f1 = f2;
            f2 = temp;
            if(temp==n){
                return true;
            }
            else if(temp>n){
                return false;
            }
        }
    }
}


int main(){
    int number = 10;
    bool ans = checkMember(number);
    if (ans == true){
        cout << "The number is a fibonacci number.";
    }else{
        cout<<"The number is not fibonacci number";
    }

    return 0;
}