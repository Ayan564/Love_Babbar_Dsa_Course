#include<iostream>
using namespace std;

bool searchInArray(int arr[], int size, int index, int target){
    // 2 base case

    // not found
    if(index >= size){
        return false;
    }
    //found
    if(arr[index] == target){
        return true;
    }


    // recursive relation
    return searchInArray(arr,size,index+1,target);


    // processing
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int index = 0;
    int target = 30;
    bool ans = searchInArray(arr,size,index,target);
    cout << ans << endl;
    return 0;
}