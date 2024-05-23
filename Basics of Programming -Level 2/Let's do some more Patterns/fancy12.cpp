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

int main(){
    int n;
    cin >> n;
    fancy12(n);
    return 0;
}