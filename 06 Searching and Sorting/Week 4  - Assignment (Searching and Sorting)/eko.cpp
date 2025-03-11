#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector<long long>& trees, long long m, long long mid){
    long long wood = 0;
    for(int i=0; i<trees.size(); i++){
        if(trees[i] > mid){
            wood += trees[i] - mid;
        }
    }
    return wood >= m;
}

long long maxSawBladeHeight(vector<long long>& trees, long long m){
    long long start = 0, end = *max_element(trees.begin(), trees.end()), ans = -1;

    while(start <= end){
        long long mid = start + (end-start) / 2;
        if(isPossibleSolution(trees, m, mid)){
            ans = mid; // store and compute
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    long long n,m;
    cout << "Enter the number of trees and the required wood: ";
    cin >> n >> m;
    vector<long long> trees;
    cout << "Enter the height of the trees: ";
    while(n--){
        long long height;
        cin >> height;
        trees.push_back(height);
    }
    cout << "Maximum saw blade height: " << maxSawBladeHeight(trees,m) << endl;
    return 0;
}