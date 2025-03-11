#include<iostream>
using namespace std;

void populate(int arr[],int n){
    int j=1;
    for(int i=0; i < n; i = i + 2){
        arr[n-j] = i+2;
        arr[j-1] = i+1;
        j++;
    }
}

int main(){
    int array[6] = {0};
    populate(array,6);
    for(int i=0; i<6; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    return 0;
}