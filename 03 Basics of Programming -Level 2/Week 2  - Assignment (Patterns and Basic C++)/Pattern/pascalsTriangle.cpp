#include<iostream>
using namespace std;

// formula of Binomial Coefficient
// c = c * (i-j) / j    where i = [1,n] and j = [1,i]

void pascalsTriangle(int n){
    for(int i=1; i<n; i++){
        int c=1;
        for(int j=1; j <= i; j++){
            cout << c <<" ";
            c = c * (i-j)/j;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    pascalsTriangle(n);

    return 0;
}