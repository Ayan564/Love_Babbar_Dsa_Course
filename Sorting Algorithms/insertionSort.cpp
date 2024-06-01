#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v){
    for(int i=0; i<v.size()-1; i++){
        cout <<v[i] <<" ";
    }
    cout << endl;
}

void insertionSort(vector<int> &v){
    int n= v.size();
    for(int i=1; i<n; i++){
        int key = v[i];
        int j =i-1;
        while (j >= 0 && v[j] > key)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

int main(){
    vector<int> v = {5,3,0,-1,33,56,4};
    cout <<"The elements before sorting: ";
    print(v);
    cout <<"The elements after sorting: ";
    insertionSort(v);
    print(v);
    return 0;
}