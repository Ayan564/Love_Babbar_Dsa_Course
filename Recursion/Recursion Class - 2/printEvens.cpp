#include<iostream>
using namespace std;

void printAllEvens(int arr[], int size, int index){
    if(index >= size){
        return;
    }
    if(!(arr[index] & 1)){
        cout<<arr[index]<<" ";
    }
    printAllEvens(arr,size,index+1);
}

int main(){
    int arr[] = {10,11,12,13,14,15};
    int size = 6;
    int index = 0;
    printAllEvens(arr,size,index);
    return 0;
}