#include<iostream>
#include<limits.h>
using namespace std;

int maxInArray(int arr[], int size, int index, int &ans){
    // base case
    if(index >= size){
        return -1;
    }
    // 1 case hum solve karenge
    ans = max(ans,arr[index]);
    // baki recursion samhal lega
    maxInArray(arr,size,index+1,ans);
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int index = 0;
    int ans = INT_MIN;
    maxInArray(arr,size,index,ans);
    cout << "Maximum number is: " << ans << endl;
    return 0;
}