#include<iostream>
using namespace std;

int binarySearch(int array[], int size, int target){
    int start = 0, end = size - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(array[mid] == target){
            return 1;
        }
        else if(target < array[mid]){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return 0;
}

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int array[size];
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
    
    cout << "The elements of the array are: ";
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    
    int ans = binarySearch(array, size, target);
    if(ans == 1){
        cout << "Element is present." << endl;
    }
    else{
        cout << "Element is not present." << endl;
    }
    
    return 0;
}
