#include<iostream>
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

void convertToUpperCase(char arr[], int size){
    int len = getLength(arr,size);
    int i=0;
    int j=len-1;
    while (arr[i] != '\0')
    {
        char ch = arr[i];
        if(arr[i] >= 'a' && arr[i] <= 'z'){
            // process to convert lower case to UPPER case
            ch = ch - 'a' +'A';
            arr[i] = ch;
        }
        i++;
    }
}

int main(){
    char arr[500];
    cin >> arr;
    convertToUpperCase(arr,500);
    cout << arr;
    return 0;
}