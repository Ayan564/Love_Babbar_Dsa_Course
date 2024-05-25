#include<iostream>
using namespace std;

int findUnique(int array[], int size){
    int ans = 0;
    for(int i=0; i<size; i++){
        ans = ans ^ array[i];
    }
    return ans;
}

int main(){
    int array[5] = {1,1,3,3,5};
    int size = 5;
    int ans = findUnique(array,size);
    cout << "The unique element is: " << ans <<endl;
    return 0;
}