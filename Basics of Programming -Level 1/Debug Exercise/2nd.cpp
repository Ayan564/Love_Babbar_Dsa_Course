/*
Pattern
1
23
345
4567
*/
#include<iostream>
using namespace std;

int main(){
    // set the input of n for stopping the infinite loop
    int n=5;
    int i=1;
    while(i<n){
        int j = i,count = 1;
        // run the inner loop as the number of row times
        while(count<=i){
            cout<<j;
            j = j + 1;
            count = count + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}