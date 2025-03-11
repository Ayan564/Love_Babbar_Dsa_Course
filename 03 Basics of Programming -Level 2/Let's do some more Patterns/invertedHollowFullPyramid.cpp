#include<iostream>
using namespace std;

void invertedHollowFullPyramid(int n){
    for (int row=0; row<n; row++){
        for(int col=0; col<row; col++){
            cout << " ";
        }
        for(int col=0; col<n-row; col++){
            if(row == 0 || row == n-1 || col == 0 || row+col == n-1){
            cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin >> n;
    invertedHollowFullPyramid(n);
    return 0;
}