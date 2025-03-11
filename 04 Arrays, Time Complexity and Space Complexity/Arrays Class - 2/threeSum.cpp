// Note: No are not duplicate in this code, the logic of the code only correct for non duplicate array

#include<iostream>
using namespace std;

void threeSum(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i] + arr[j] + arr[k] == target){
                    cout << "The elements are: "<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                }
            }
        }
    }
}

int main(){
    int array[7] = {10,20,40,90,80,50,60};
    int size = 7;
    int target = 150;
    threeSum(array,size,target);
    return 0;
}