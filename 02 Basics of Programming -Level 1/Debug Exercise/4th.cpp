/*
Pattern
N = 4
1
22
333
4444
*/
#include<iostream>
using namespace std;

int main(){
  int n,i,j;
    cin>>n;
    // run the outer loop 4 times
    for(i=1;i<=n;i++){
      // run the outer loop as number of row times
        for(j=1;j<=i;j++){
	        cout<<i;
        }
    cout<<endl;
    }
}