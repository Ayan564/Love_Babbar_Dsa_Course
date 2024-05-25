#include<iostream>
using namespace std;

void onesComplement(int arr[], int size){
      for(int i=0; i<size; i++){
            if(arr[i] == 0){
                  arr[i] = 1;
            }
            else if(arr[i] == 1){
                  arr[i] = 0;
            }
      }
}

void twosComplement(int arr[], int size){
      int i = size-1;
      while(i >= 0 && arr[i] != 1){
            i--;
      }
      i--;
      for(;i>=0;i--){
            if(arr[i] == 0){
                  arr[i] = 1;
            }
            else if(arr[i] == 1){
                  arr[i] = 0;
            }
      }
}



int main(){
      int array[6] = {0,0,1,0,1,0};
      int size = 6;
      // onesComplement(array, size);
      // cout << "The one's complement of the array is: ";
      // for(int i=0; i<size; i++){
      //       cout << array[i] <<" ";
      // }
      twosComplement(array, size);
      cout << "The two's complement of the array is: ";
      for(int i=0; i<size; i++){
            cout << array[i] <<" ";
      }
      cout<<endl;
      return 0;
}