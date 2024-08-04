#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void solve(stack<int>& s, vector<int>& arr, vector<int>& ans){
    int n = arr.size();
    for(int i=n-1; i>=0; i--){
        int element = arr[i];
        // ish element ke liye stack check karne jana ha
        while(s.top() >= element){
            s.pop();
        } 
        // jab yaha pohochunga iska matlab stack ke top par koi chota element ha
        ans.push_back(s.top());
        s.push(element);
    }
}

int main(){

    // input -> vector
    vector<int> v;
    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);


    // solve using stack
    stack<int> s;
    s.push(-1);
    vector<int> ans(s.size());
    solve(s,v,ans);
    reverse(ans.begin(),ans.end());
    for(auto ele: ans){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}