#include<iostream>
using namespace std;

void printArray(int arr[], int size, int index){
    // base case
    if(index == size){
        return;
    }
    // recursive relation
    cout<< arr[index] << " ";
    printArray(arr,size,index+1);
    // processing
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int index = 0;
    printArray(arr,size,index);
    return 0;
}