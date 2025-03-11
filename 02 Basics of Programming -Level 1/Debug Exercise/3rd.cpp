/*
Pattern
N = 4
   *
  ***
 *****
*******
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=0;
    while(i<=n){
        int j=0;
        while(j<n-i){
            cout<<" ";
            j = j + 1;
        }
         j = 0;
        while(j<2*i-1){
            cout<<"*";
            j = j + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}