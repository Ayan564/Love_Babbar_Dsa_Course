#include<iostream>
using namespace std;

void printAllEvens(int arr[], int size, int index){
    if(index >= size){
        return;
    }
    // 1 case hum solve karenge
    if(!(arr[index] & 1)){
        cout<<arr[index]<<" ";
    }
    // baki recursion samhal lega
    printAllEvens(arr,size,index+1);
}

int main(){
    int arr[] = {10,11,12,13,14,15};
    int size = 6;
    int index = 0;
    printAllEvens(arr,size,index);
    return 0;
}