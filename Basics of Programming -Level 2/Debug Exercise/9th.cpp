#include<iostream>
using namespace std;

/*
Pattern for N = 4
4444
333
22
1
*/

int main(){
  int i,j,n;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            cout<<n-i;
        }
        cout<<endl;
    }
}