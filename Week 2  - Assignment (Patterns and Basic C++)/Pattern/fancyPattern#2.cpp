#include<iostream>
using namespace std;

void fancyPattern2(int n){
    int c=1;

    // growing phase
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<c;
            c++;
            if(j<i){
                cout<<"*";
            }
        }
        cout<<endl;
    }

    //shrinking phase
    int start = c-n;
    for(int i=0; i<n; i++){
        int k =start;
        for(int j=0; j<=n-i-1; j++){
            cout<<k;
            k++;
            if(j < n-i-1){
                cout<<"*"
;            }
        }
        start = start - (n-i-1);
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    fancyPattern2(n);
    return 0;
}