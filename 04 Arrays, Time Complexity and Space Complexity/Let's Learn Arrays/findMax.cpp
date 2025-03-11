#include<iostream>
#include<limits.h>
using namespace std;

int findMax(int arr[], int size){
    int maxAns = INT_MIN;
    for(int i=0; i<size; i++){
        // if(arr[i] > max){
        //     max = arr[i];
        // }
        maxAns = max(maxAns, arr[i]);
    }
    return maxAns;
}

int main(){
    int array[100], size;

    cout<<"Enter the size of the array: ";
    cin >> size;
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
    
    cout << "The elements of the array are: ";
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    int ans = findMax(array, size);
    cout << "The maximum number of the array is: "<< ans ;
    return 0;
}