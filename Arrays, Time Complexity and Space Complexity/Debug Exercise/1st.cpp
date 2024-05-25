#include<iostream>
using namespace std;

int main(){
    int n, sum=0;
    cin >> n;
    int input[n];
    for(int i=0;i<n;i++){
        // input the number of n times
        cin >> input[i];
    }
     for(int i=0; i<n; i++){
         sum = sum + input[i];
     }
    cout << sum << endl;
    return 0;
}