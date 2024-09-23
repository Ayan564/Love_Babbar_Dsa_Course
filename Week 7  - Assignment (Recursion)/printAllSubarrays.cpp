#include<iostream>
#include<vector>
using namespace std;

void printAllSubarrays_util(vector<int>& nums, int start, int end){
    // base case
    if(end >= nums.size()){
        return;
    }
    // ek case hum solve karenge
    for(int i=start; i<=end; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    // baki recursion samhal lega
    printAllSubarrays_util(nums, start, end+1);

}

void printAllSubarrays(vector<int>& nums){
    for(int start = 0; start < nums.size(); start++){
        int end = start;
        printAllSubarrays_util(nums, start, end);
    }
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    printAllSubarrays(nums);
    return 0;
}