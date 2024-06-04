#include<iostream>
using namespace std;

void replaceCharecter(char originalChar, char newChar, char arr[], int size){
    for(int i=0; i<size; i++){
        if(arr[i] == originalChar){
            arr[i] = newChar;
        }
    }
}

int main(){
    char arr[500];
    cout << "Enter the char array: ";
    cin >> arr;
    replaceCharecter('@','A',arr,500);
    cout << "After replaceing the array is: ";
    cout << arr;
    return 0;
}