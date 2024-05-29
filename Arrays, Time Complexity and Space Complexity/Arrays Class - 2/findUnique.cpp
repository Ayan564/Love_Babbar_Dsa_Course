#include<iostream>
#include<algorithm>
using namespace std;

int findUnique(int array[], int size){
    int ans = 0;
    for(int i=0; i<size; i++){
        ans = ans ^ array[i];
    }
    return ans;
}

int findUnique1(int array[], int size){
    int ans = -1, i=0;
    sort(array,array+size);
    while(i<size){
        if(i+1 < size && array[i] == array[i+1]){
            i += 2;
        }
        else{
            ans = array[i];
            break;
        }
    }
}

int main(){
    int array[7] = {1,1,3,3,5,2,2};
    int size = 7;
    int ans = findUnique1(array,size);
    cout << "The unique element is: " << ans <<endl;
    return 0;
}