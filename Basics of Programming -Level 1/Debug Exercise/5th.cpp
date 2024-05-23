/*
Pattern
N = 4
1
21
321
4321
*/
#include<iostream>
using namespace std;

int main(){
  int i,j,n;
    cin>>n;
    // run the outer loop from 0 to n-1
    for(i=0;i<n;i++){
      // Store the number into ans variable and decrement that after using it
      int ans = i+1;
      // run the innre loop from 0 to i+1 as this is a half pyramid pattern
        for(j=0;j<i+1;j++){
          cout<<ans;
          ans--; // decrement the ans vaiable for decrease the number
        }
        cout<<endl;
        
    }
}