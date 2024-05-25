#include<iostream>
using namespace std;

void findFirstOccuence(int array[], int size, int target, int &ans){
    int start = 0, end = size - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(array[mid] == target){
            // store and compute
            ans = mid;
            end = mid -1; // going to the left portion
        }
        else if(target < array[mid]){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
}

void findLastOccuence(int array[], int size, int target, int &ans){
    int start = 0, end = size - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(array[mid] == target){
            // store and compute
            ans = mid;
            start = mid +1; // going to the right portion
        }
        else if(target < array[mid]){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
}

int main(){
    int array[100],size;

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
    
    int firstOcc = -1;
    int lastOcc = -1;
    findFirstOccuence(array, size, target,firstOcc);
    findLastOccuence(array, size, target,lastOcc);
    cout << "The first occurence of the target element is: "<< firstOcc<<endl;
    cout << "The last occurence of the target element is: "<< lastOcc<<endl;
    cout << "The total no of occurence is: " << lastOcc-firstOcc+1<<endl;
    
    return 0;
}
