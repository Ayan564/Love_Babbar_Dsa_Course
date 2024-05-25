#include<iostream>
using namespace std;
int linearSearch(int arr[], int n ,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

int main(){
    int array[5] = {1,2,3,4,5};
    int ans = linearSearch(array,5,4);
    if(ans == -1){
        cout<<"The value is not present";
    }
    else{
        cout<<"The value is present at index: "<<ans;
    }
    return 0;
}