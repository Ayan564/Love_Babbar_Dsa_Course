#include<iostream>
using namespace std;

pair<int,int> twoSum(int arr[], int size,int target){
    pair<int,int>p = {-1,-1};
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] + arr[j] == target){
                p.first = arr[i];
                p.second = arr[j];
            }
        }
    }
    return p;
}

int main(){
    int array[8] = {10,20,90,80,50,60,20,80};
    int size = 8;
    int target = 160;
    pair<int,int>ans;
    ans = twoSum(array,size,target);
    cout << "Elements are: "<<ans.first <<" "<<ans.second<<endl;
    return 0;
}