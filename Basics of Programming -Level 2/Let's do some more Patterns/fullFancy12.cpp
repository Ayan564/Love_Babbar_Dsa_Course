#include<iostream>
using namespace std;

void fancy12(int n){
    for(int i=0; i<n;i++){
        for(int j=0;j<2*i+1;j++){
            if(!(j&1)){
                cout<< i+1;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}

void invertedFancy12(int n){
    n--;
    for(int i=0; i<n; i++){
        for(int j=0;j<2*(n-i)-1;j++){
            if(!(j&1)){
                cout<< n-i;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}

void fullFancy12(int n){
    fancy12(n);
    invertedFancy12(n);
}

int main(){
    int n;
    cin >> n;
    fullFancy12(n);
    return 0;
}