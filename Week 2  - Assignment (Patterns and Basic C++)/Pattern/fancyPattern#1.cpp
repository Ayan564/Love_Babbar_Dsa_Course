#include<iostream>
using namespace std;

void fancyPattern1(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n-i-2; j++){
            cout<<"*";
        }
        for(int j=0; j<2*i+1; j++){
            if(!(j&1)){
                cout<<i+1;
            }else{
                cout<<"*";
            }
        }
        for(int j=0; j<2*n-i-2; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    fancyPattern1(n);
    return 0;
}