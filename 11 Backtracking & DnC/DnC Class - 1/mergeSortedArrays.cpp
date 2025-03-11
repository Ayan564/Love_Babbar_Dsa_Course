#include<iostream>
#include<vector>
using namespace std;

void mergeTwoSortedArrays(vector<int>& arr, vector<int>& brr, vector<int>& crr){
    int i = 0, j=0;
    int x = arr.size();
    int y = brr.size();
    while(i < x && j < y){
        if(arr[i] == brr[j]){
            crr.push_back(arr[i]);
            i++;j++;
        }
        else if(arr[i] < brr[j]){
            crr.push_back(arr[i]);
            i++;
        }
        else{
            crr.push_back(brr[j]);
            j++;
        }
    }
    while(i < x){
        crr.push_back(arr[i]);
        i++;
    }
    while(j < y){
        crr.push_back(brr[j]);
        j++;
    }
}

int main(){

    vector<int> arr = {10,30,50,70,90,110};
    vector<int> brr = {20,40,60,80,100};
    vector<int> crr;

    mergeTwoSortedArrays(arr,brr,crr);
    for(auto num: crr){
        cout << num << " ";
    }
    return 0;
}