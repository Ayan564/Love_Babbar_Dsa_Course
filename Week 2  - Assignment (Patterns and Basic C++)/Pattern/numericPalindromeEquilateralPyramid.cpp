#include<iostream>
using namespace std;

void numericPalindromeEqulateralPyramid(int n){
    int k =n;
    for(int row=0; row<n; row++){
        int count = 1;
        for(int col=0; col<n-row-1; col++){
            cout<<"  ";
        }
        for(int col=0; col<row+1; col++){
            cout<<count<<" ";
            count++;
        }
        count -= 2;
        for(int col=0; col<row && count >= 0; col++){
            cout<<count<<" ";
            count--;
        }
        cout<<endl;
    }


    //     for(int col=0; col<k; col++){
    //         if(col < n-row-1){
    //             cout<<"  ";
    //         }
    //         else if(col <= n-1){
    //             cout<<count<<" ";
    //             count++;
    //         }
    //         else if(col == n){
    //             count = count - 2;
    //             cout << count<<" ";
    //             count--;
    //         }
    //         else{
    //             cout << count<<" ";
    //             count--;
    //         }
    //     }
    //     k++;
    //     cout<<endl;
    // }
}

int main(){
    int n;
    cin >> n;
    numericPalindromeEqulateralPyramid(n);
    return 0;
}