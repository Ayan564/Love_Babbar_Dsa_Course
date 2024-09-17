#include<iostream>
#include<cstring>
using namespace std;

// from left to right
void lastOccurenceLR(string& s, char key, int i, int& ans){
    // base case
    if(i >= s.size()){
        return;
    }
    // ek case hum solve karenge
    if(s[i] == key){
        ans = i;
    }
    lastOccurenceLR(s, key, i+1, ans);
}

// from right to left
void lastOccurenceRL(string& s, char key, int i, int& ans){
    // base case
    if(i < 0){
        return;
    }
    // ek case hum solve karenge
    if(s[i] == key){
        ans = i;
        return;
    }
    lastOccurenceRL(s, key, i-1, ans);
}

int main(){
    // const char* s = "abcddedg";
    string s = "abcddedg";
    char key = 'd';
    int ans = -1;
    lastOccurenceLR(s, key, 0, ans);
    cout << ans << endl;
    ans = -1;
    lastOccurenceRL(s, key, s.size()-1, ans);
    cout << ans << endl;
    cout << s.find_last_of(key) << endl;
    // const char* p = strrchr(s, key);
    // cout << p - s << endl;
    return 0;
}