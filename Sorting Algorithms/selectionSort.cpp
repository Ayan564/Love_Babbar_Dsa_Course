#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v){
    for(int i=0; i<v.size()-1; i++){
        cout <<v[i] <<" ";
    }
    cout << endl;
}

void selectionSort(vector<int> &v){
    int n = v.size();
    for(int i=0; i<n-1; i++){
        int minIndex = i; // Let, ith element is the smallest element
        for(int j=i+1; j<n; j++){
            // step 1: find the smallest element in the range of [i+1 to n-1]
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        // step 2: swap the min element with the ith element
        swap(v[i], v[minIndex]);
    }
}

int main(){
    vector<int> v = {5,3,0,-1,33,56,4};
    cout <<"The elements before sorting: ";
    print(v);
    cout <<"The elements after sorting: ";
    selectionSort(v);
    print(v);
    return 0;
}