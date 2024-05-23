/*
Pattern
N = 5
E
DE
CDE
BCDE
ABCDE
*/
#include<iostream>
using namespace std;

int main() {
    int i,j,n;;
    cin>>n;
    for(i=0;i<n;i++){
        char p='E'-i;
        for(j=0;j<i+1;j++){
            cout<<p;
            p++;  
        }
        cout<<endl;
    }
}