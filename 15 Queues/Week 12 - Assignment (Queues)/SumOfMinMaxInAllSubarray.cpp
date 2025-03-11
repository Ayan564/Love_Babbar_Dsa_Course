#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int sumOfMinMaxAllSubarray(vector<int>& nums, int k) {
    deque<int> dq1, dq2;
    int ans = 0;
    // process first window
    for(int i=0; i<k; i++){
        int element = nums[i];
        while(!dq1.empty() && nums[dq1.back()] <= element){
            dq1.pop_back();
        }
        while(!dq2.empty() && nums[dq2.back()] >= element){
            dq2.pop_back();
        }
        dq1.push_back(i);
        dq2.push_back(i);
    }
    
    ans += nums[dq1.front()] + nums[dq2.front()];

    // process remaining windows
    for(int i=k; i<nums.size(); i++){
        // removal
        if(dq1.front() < i-k+1) dq1.pop_front();
        if(dq2.front() < i-k+1) dq2.pop_front();
        // addition
        int element = nums[i];
        while(!dq1.empty() && nums[dq1.back()] <= element){
            dq1.pop_back();
        }
        while(!dq2.empty() && nums[dq2.back()] >= element){
            dq2.pop_back();
        }
        dq1.push_back(i);
        dq2.push_back(i);
        // store the answer
        ans += nums[dq1.front()] + nums[dq2.front()];
    }
    return ans;
}

int main(){
    vector<int> nums = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumOfMinMaxAllSubarray(nums, k) << endl;

    return 0;
}