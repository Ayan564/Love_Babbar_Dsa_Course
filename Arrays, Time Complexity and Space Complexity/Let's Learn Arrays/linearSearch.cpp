#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target){
            return 1;
        }
    }
    return 0;
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
    
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    
    int ans = linearSearch(array, size, target);
    if(ans == 1){
        cout << "Element is present." << endl;
    }
    else{
        cout << "Element is not present." << endl;
    }
    
    return 0;
}