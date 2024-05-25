#include<iostream>
using namespace std;

void reverseArray(int arr[], int size, int shift){
    int finalShift = shift % size;
    cout << "The effective steps of rotation are: "<<finalShift<<endl;
    if(finalShift == 0){
        return;
    }

    // step1: copy the finalShift number of elements into temp array
    int temp[100];
    int index = 0;
    for(int i=size-finalShift;i<size;i++){
        temp[index] = arr[i];
        index++;
    }

    // step2: shift the elements by finalShift
    for(int i=size-1; i>=0; i--){
        arr[i] = arr[i-finalShift];
    }

    // step3: copy temp elements into original array
    for(int i=0;i<finalShift;i++){
        arr[i] = temp[i];
    }
}


int main(){
    int array[6] = {11,22,33,44,55,66};
    int size = 6;
    int shift;
   // print the array
    cout << "The rotate array is: ";
    for(int i=0; i<size; i++){
        cout<<array[i] <<" ";
    }
    cout<<endl;

    cout << "Enter the no of shift: ";
    cin >> shift;
    reverseArray(array, size,shift);
    // print the array
    cout << "The rotate array is: ";
    for(int i=0; i<size; i++){
        cout<<array[i] <<" ";
    }
    cout<<endl;

    return 0;
}