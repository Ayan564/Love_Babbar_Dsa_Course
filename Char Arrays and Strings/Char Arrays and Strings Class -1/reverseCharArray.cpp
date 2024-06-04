#include<iostream>
#include<string>
using namespace std;

int getLength(char arr[], int n){
    int i=0;
    int count =0;
    while(arr[i] != '\0'){
        count++;
        i++;
    }
    return count;
}

void reverseCharArray(char arr[], int n){
    int len = getLength(arr,n);
    int i=0, j=len-1;
    while(i<=j){
        swap(arr[i++],arr[j--]);
    }
    return;
}

int main(){
    char arr[100];
    int size = 100;
    cout <<"Enter the char array: ";
    cin >> arr;
    reverseCharArray(arr,size);
    cout <<"The reverse array is: "<< arr;
    return 0;
}