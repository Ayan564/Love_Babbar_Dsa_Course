#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char arr[100];
    cout <<"Enter the input array: ";
    cin >> arr;

    char brr[100];
    cout <<"Enter the input array: ";
    cin >> brr;

    char ans[100];
    cout <<"The length of the array arr is: "<<strlen(arr) << endl;
    cout <<"The final array is: ";
    cout << strcat(arr,brr) << endl;

    return 0;
}