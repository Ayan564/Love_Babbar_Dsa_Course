#include<iostream>
#include<algorithm>
using namespace std;

// using in-built sort() method

void sortZeroOne1(int arr[],int size){
      sort(arr,arr+size);
      cout<<"The sorted array is: ";
      for(int i=0; i<size; i++){
            cout<<arr[i] << " ";
      }
}

// using count the number of 1's and 0's

void sortZeroOne2(int arr[], int size){
      int countZero = 0;
      int countOne = 0;
      for(int i=0; i<size; i++){
            if(arr[i] == 0){
                  countZero++;
            }
            if(arr[i] == 1){
                  countOne++;
            }
      }
      fill(arr,arr+countZero,0);
      fill(arr+countZero,arr+size,1);

      cout<<"The sorted array is: ";
      for(int i=0; i<size; i++){
            cout<<arr[i] << " ";
      }
}

// using two-pointer approach

void sortZeroOne3(int arr[], int size){
      int left=0, right=size-1;
      while ( left < right ) {
            if(arr[left] == 1 && arr[right] == 0){
                  swap(arr[left++],arr[right--]);
            }
            else{
                  if(arr[left] == 0){
                        left++;
                  }
                 if(arr[right] == 1){
                        right--;
                  }
            }
      }
      cout<<"The sorted array is: ";
      for(int i=0; i<size; i++){
            cout<<arr[i] << " ";
      }
}

int main(){
      int array[10] = {0,0,1,1,0,1,0,0,1,0};
      int size = 10;
      sortZeroOne3(array, size);
      return 0;
}