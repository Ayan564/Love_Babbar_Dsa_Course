#include<iostream>
#include<vector>
using namespace std;

void printSubsequence(string str, int i, string output,vector<string>& ans){
    if(i == str.length()){
        ans.push_back(output);
        return;
    }
    char ch = str[i];
    // exclude
    printSubsequence(str, i+1, output,ans);
    // include
    printSubsequence(str, i+1, output+ch,ans);

}

int main(){
    string str = "abc";
    string output = "";
    int index = 0;
    vector<string> ans;
    printSubsequence(str, index, output,ans);
    for(auto str : ans){
        cout << str << " ";
    }
    return 0;
}