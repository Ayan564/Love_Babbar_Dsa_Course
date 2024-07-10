#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int s, int e, int mid){
    int leftLength = mid-s+1, rightLength = e-mid;
    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];

    int index = s;
    for(int i=0; i<leftLength; i++){
        leftArr[i] = arr[index];
        index++;
    }
    index = mid+1;
    for(int i=0; i<rightLength; i++){
        rightArr[i] = arr[index];
        index++;
    }
    int leftIndex = 0, rightIndex = 0;
    int mainArrayIndex = s;
    while(leftIndex < leftLength && rightIndex < rightLength){
        if(leftArr[leftIndex] < rightArr[rightIndex]){
            arr[mainArrayIndex] = leftArr[leftIndex];
            leftIndex++;
            mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex] = rightArr[rightIndex];
            rightIndex++;
            mainArrayIndex++;
        }
    }
    while(leftIndex < leftLength){
        arr[mainArrayIndex] = leftArr[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }
    while(rightIndex < rightLength){
        arr[mainArrayIndex] = rightArr[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }
}


void mergeSort(vector<int>& arr, int s, int e){
    // base case
    if(s >= e){return;}
    int mid = s+(e-s)/2;
    // sove the left part
    mergeSort(arr, s, mid);
    // solve the right part
    mergeSort(arr, mid+1, e);
    // merge the two parts
    merge(arr,s,e,mid);
}

int main(){
    vector<int> arr = {10,5,20,17,34,25};
    int s = 0, e = arr.size();
    mergeSort(arr,s,e);
    for(auto num: arr){
        cout << num << " ";
    }
    return 0;
}