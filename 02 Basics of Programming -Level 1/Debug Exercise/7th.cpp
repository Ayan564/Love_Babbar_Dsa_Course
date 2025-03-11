/*
Pattern
N = 4
   1
  232
 34543
4567654
*/
#include<iostream>
using namespace std;
int main(){
    int no;
    cin>>no;
    int i=0;
    // int n = 2*no;
    while(i<no){
        int j = 0;
        while(j<no-i-1){
            cout<<" ";
            j = j + 1;
        }
        int k = i+1;
        while(k<=2*i+1){
            cout<<k;
            k = k + 1;
        }
        int l = k -2;
        while(l >=i+1){
            cout<<l;
            l = l - 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}