#include<iostream>
using namespace std;

bool sortedOrNot(int arr[], int size, int index){
    if(index == size-1){
        return true;
    }
    bool currAns = false;
    bool recursionAns = false;
    // 1 case hum solve karenge
    if(arr[index] < arr[index+1]){
        currAns = true;
    }
    // baki recursion samhal lega
    recursionAns = sortedOrNot(arr, size, index+1);
    return (currAns && recursionAns);
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int index = 0;
    bool ans = sortedOrNot(arr,size,index);
    cout << ans <<endl;
    return 0;
}