#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int>&arr, int start, int end, int target){
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int exponentialSearch(vector<int>& arr, int n, int x){
    if(arr[0] == x){
        return 0;
    }
    int i = 1;
    while(i < n && arr[i] <= x){
        i = i * 2; // i *= 2 // i <<= 1
    }
    return bs(arr, i/2, min(i, n-1), x);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();
    int x = 3;
    int ans = exponentialSearch(arr, n, x);
    cout << ans << endl;

    return 0;
}