#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int s, int e, int target){
    int mid = s+(e-s)/2;
    if(s > e){
        return -1;
    }
    // 1 case hum solve karenge
    if(arr[mid] == target){
        return mid;
    }
    // baki recursion samhal lega
    if(target > arr[mid]){
        return binarySearch(arr,size,mid+1,e,target);
    }
    else{
        return binarySearch(arr,size,s,mid-1,target);
    }
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int s = 0;
    int e = size-1;
    int target = 60;
    int ans = binarySearch(arr,size,s,e,target);
    cout << "The index of the ans is: "<<ans;
    return 0;
}