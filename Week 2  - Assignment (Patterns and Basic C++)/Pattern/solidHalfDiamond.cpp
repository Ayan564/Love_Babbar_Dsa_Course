#include<iostream>
using namespace std;

void solidHalfDiamond(int n){
    for(int row=0; row<2*n-1; row++){
        int cond = row < n ? row : n - (row % n) - 2;
        // if(row < n){ // growing phase of diamond
        //     cond =row;
        // }
        // else{ // shrinking phase of diamond
        //     cond = n - (row % n) - 2;
        // }
        for(int col = 0; col <= cond ; col++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    solidHalfDiamond(n);
    return 0;
}