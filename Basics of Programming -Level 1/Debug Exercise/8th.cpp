#include<iostream>
using namespace std;
/*
Pattern
N = 5
  *
 ***
*****
 ***
  *
*/
// void printPatt(int n){
//     int i=1;
//     while(i<=n){
//         int gaps = n-2*i,k=1;
//         if(i>(n)/2){
//             int no = (n+1)/2;
//             gaps = 2*(i%no);
//         }
//         while(k<=gaps/2){
//             cout<<" ";
//             k = k + 1;
//         }
//         int ch = n - 1 - gaps;
//         while(ch>=1){
//             cout<<"*";
//             ch = ch - 1;
//         }
//         k = 1;
//         while(k<=gaps/2){
//             cout<<" ";
//             k = k + 1;
//         }
//         cout<<"\n";
//         i = i + 1;
//     }
// }

void upPattern(int n){
    for(int i=0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            cout<<" ";
        }
        for(int j = 0; j<2*i+1; j++){
            cout<<"*";
        }
    cout<<endl;
    }
}

void downPattern(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<" ";
        }
        for(int j=0; j < 2*(n-i)-1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void printPatt(int n){
    n = (n/2)+1;
    upPattern(n);
    n = n -1;
    downPattern(n);
}

int main(){
    printPatt(5);
    return 0;
}