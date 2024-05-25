#include<iostream>
#include<algorithm>
using namespace std;

void reverseArray1(int arr[], int size){
    int start = 0, end = size-1;
    while(start <= end){
        swap(arr[start++], arr[end--]);
    }
    cout << "The reverse elements of the array are: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}
void reverseArray2(int arr[], int size){
    int start = 0, end = size-1;
    arr[start] = arr[start] ^ arr[end];
    arr[end] = arr[end] ^ arr[start];
    arr[start] = arr[start] ^ arr[end];
    cout << "The reverse elements of the array are: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
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
    
    // 1. Custom reverse of an array using two-pointer approach
    // reverseArray1(array, size);

    // 2. Custom reverse of an array without using swap function
    reverseArray2(array, size);

    // 3. using STL ( C++ library)
    // reverse(array,array+size);
    // cout << "The reverse elements of the array are: ";
    // for(int i = 0; i < size; i++){
    //     cout << array[i] << " ";
    // }
    return 0;
}