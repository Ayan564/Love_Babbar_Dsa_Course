#include<iostream>
using namespace std;

void hollowFullPyramid(int n){
    for (int row=0; row<n; row++){
        for(int col=0; col<n-row-1; col++){
            cout << " ";
        }
        for(int col=0; col<row+1; col++){
            if(row == 0 || col == 0 || col == row +1 -1){
            cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout<<endl;
    }
}

void invertedHollowFullPyramid(int n){
    for (int row=0; row<n; row++){
        for(int col=0; col<row; col++){
            cout << " ";
        }
        for(int col=0; col<n-row; col++){
            if(row == n-1 || col == 0 || row+col == n-1){
            cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout<<endl;
    }
}

void hollowDiamond(int n){
    hollowFullPyramid(n);
    invertedHollowFullPyramid(n);
}


int main(){
    int n;
    cin >> n;
    hollowDiamond(n);
    return 0;
}