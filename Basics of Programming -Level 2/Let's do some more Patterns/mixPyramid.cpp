#include<iostream>
using namespace std;

void mixPyramid(int n){
    // Part - I
    for (int i=0; i<n; i++){
        // first part => ( print the half pyramid with starts)
        for(int j=0; j<n-i; j++){
            cout << "* ";
        }
        // second part => ( print the full pyramid with spaces )
        for(int j=0; j<2*i+1; j++){
            cout << "  ";
        }
        // third part => ( print the half pyramid with starts )
        for(int j=0; j<n-i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    
    // Part - II
    for (int i=0; i<n; i++){
        // first part => ( print the half pyramid with starts)
        for(int j=0; j<i+1; j++){
            cout << "* ";
        }
        // second part => ( print the full pyramid with spaces )
        for(int j=0; j<2*(n-i)-1; j++){
            cout << "  ";
        }
        // third part => ( print the half pyramid with starts )
        for(int j=0; j<i+1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    mixPyramid(n);
    return 0;
}