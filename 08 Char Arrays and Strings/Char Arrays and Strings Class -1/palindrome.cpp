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

bool palindrome(char arr[], int n){
    int len = getLength(arr,n);
    int i=0, j=len-1;
    while(i<=j){
        if(arr[i] == arr[j]){
            i++; j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    char arr[100];
    int size = 100;
    cout <<"Enter the char array: ";
    cin >> arr;
    bool ans = palindrome(arr,size);
    if(ans == true){
        cout << "This is a palindrome.";
    }
    else{
        cout << "This is not a palindrome.";
    }
    return 0;
}