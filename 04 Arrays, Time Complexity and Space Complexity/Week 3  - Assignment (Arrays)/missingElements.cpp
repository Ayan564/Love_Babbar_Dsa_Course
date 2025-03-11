#include<iostream>
#include<vector>
using namespace std;

void negativeMarkingMethod(vector<int>& arr, vector<int>& ans){
    for(int i=0; i<arr.size(); i++){
        int index = abs(arr[i]) - 1;
        if(arr[index] > 0){
            arr[index] *= -1;
        }
    }
    // now all positive elements' indexes are missing elements
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > 0){
            ans.push_back(i+1);
        }
    }
}

void sortingAndSwapingMethod(vector<int>& arr, vector<int>& ans){
    int i=0; 
    while(i < arr.size()){
        int index = arr[i] - 1;
        if(arr[i] != arr[index]){
            swap(arr[i], arr[index]);
        }else{
            i++;
        }
    }
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != i+1){
            ans.push_back(i+1);
        }
    }
}

int main(){
    // vector<int> arr = {1,3, 3, 3, 4, 6, 6};
    vector<int> arr = {1, 3, 5, 3, 4};
    vector<int> ans;
    negativeMarkingMethod(arr, ans);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}