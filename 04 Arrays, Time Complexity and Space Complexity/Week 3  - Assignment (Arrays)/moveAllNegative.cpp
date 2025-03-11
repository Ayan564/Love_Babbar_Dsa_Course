#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void usingSort(vector<int> &arr){
    sort(arr.begin(), arr.end());
}

void usingTwoPointer(vector<int> &arr){
    int left = 0; int right = arr.size()-1;
    while(left < right){
        if(arr[left] < 0 ){
            left++;
        }
        else if(arr[right] > 0){
            right--;
        }
        else{
            swap(arr[left], arr[right]);
        }
    }
}

int main(){
    vector<int> arr = {1, 2, 3, -1, -2, -3, 4, 5, 6, -4, -5, -6};
    // usingSort(arr);
    usingTwoPointer(arr);
    for(auto i : arr){
        cout << i << " ";
    }
    return 0;
}