#include<iostream>
#include<limits.h>
using namespace std;

int minInArray(int arr[], int size, int index, int &ans){
    // base case
    if(index >= size){
        return -1;
    }
    // processing
    ans = min(ans,arr[index]);
    // recursive relation
    minInArray(arr,size,index+1,ans);
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int index = 0;
    int ans = INT_MAX;
    minInArray(arr,size,index,ans);
    cout << "Minimum number is: " << ans << endl;
    return 0;
}