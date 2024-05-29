#include <iostream>
using namespace std;

void butterfly1(int n){
    for(int i=0; i<2*n; i++){
        int cond = i < n ? i : n + (n-i-1);
        int spaceCount = i < n ? 2*(n-cond-1): i-cond-1;
        for(int j=0; j<2*n; j++){
            if(j<=cond){
                cout <<"*";
            }
            else if(spaceCount > 0){
                cout <<" ";
                spaceCount--;
            }
            else{
                cout << "*";
            }
        }
        cout <<endl;
    }
}

void butterfly2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout <<"*";
        }
        for(int j=0; j<2*(n-i-1); j++){
            cout<<" ";
        }
        for(int j=0; j<i+1; j++){
            cout << "*";
        }
        cout <<endl;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            cout <<"*";
        }
        for(int j=0; j<2*i; j++){
            cout<<" ";
        }
        for(int j=0; j<n-i; j++){
            cout << "*";
        }
        cout <<endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    // butterfly1(n);
    butterfly2(n);
    return 0;
}
