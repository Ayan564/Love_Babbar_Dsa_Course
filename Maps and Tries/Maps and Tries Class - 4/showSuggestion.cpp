#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class TrieNode{
    public:
    char value;
    unordered_map<int, TrieNode*> children;
    bool isTerminal;

    TrieNode(char data){
        this->value = data;
        isTerminal = false;
    }
};

void insertIntoTrie(TrieNode* root, string &word, int i = 0){
    // base case
    if(i >= word.size()){
        root->isTerminal = true;
        return;
    }

    // 1 case hum solve karenge
    char ch = word[i];
    TrieNode* child;
    // present
    if(root->children.count(ch) > 0){
        child = root->children[ch];
    }
    // absent
    else{
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    // baki recursion samhal lega
    insertIntoTrie(child, word, i+1);
}

bool searchInTrie(TrieNode* root, string &word, int i = 0){
    // base case
    if(i >= word.size()){
        return root->isTerminal;
    }

    // 1 case hum solve karenge
    char ch = word[i];
    TrieNode* child;

    // present
    if(root->children.find(ch) != root->children.end()){
        child = root->children[ch];
    }
    // absent
    else{
        return false;
    }
    // baki recursion samhal lega
    bool recursionResult = searchInTrie(child, word, i+1);
    return recursionResult;
}

void removeWord(TrieNode* root, string &word, int i = 0){
    // base case
    if(i >= word.size()){
        root->isTerminal = false;
        return;
    }

    // 1 case hum solve karenge
    char ch = word[i];
    TrieNode* child;

    // present
    if(root->children.find(ch) != root->children.end()){
        child = root->children[ch];
    }
    // absent
    else{
        return;
    }
    // baki recursion samhal lega
    removeWord(child, word, i+1);
}

void storeString(TrieNode* root, vector<string>& ans, string output){
    // base case
    if(root->isTerminal){
        ans.push_back(output);
    }
    // 1 case hum solve karenge
    for(auto i : root->children){
        char ch = i.first;
        TrieNode* child = i.second;
        output.push_back(ch);
    // baki recursion samhal lega
    storeString(child, ans, output);
    // backtracking
    output.pop_back();
    }
}

void findWordWithPrefix(TrieNode* root, string prefix, vector<string>& ans){
    // base case
    if(prefix.size() == 0){
        // print all the words with prefix
        string temp = "";
       storeString(root, ans, temp);
        return;
    }
    // 1 case hum solve karenge
    char ch = prefix[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        child = root->children[ch];
    }
    else{
        return;
    }
    // baki recursion samhal lega
    findWordWithPrefix(child, prefix.substr(1), ans);
}

vector<vector<string>> getSuggestions(TrieNode* root, string prefix){
    string temp = "";
    vector<vector<string>> ans;
    for(int i=0; i<prefix.size(); i++){
        vector<string> tempAns;
        char currCh = prefix[i];
        temp.push_back(currCh);
        findWordWithPrefix(root, temp, tempAns);
        // add prefix to tempAns array
        for(int j=0; j<tempAns.size(); j++){
            tempAns[j] = temp + tempAns[j];
        }
        ans.push_back(tempAns);
    }
    return ans;
}

int main(){
    TrieNode* root = new TrieNode('-');
    string word1 = "babbar";
    string word2 = "baby";
    string word3 = "baba";
    string word4 = "bala";
    insertIntoTrie(root, word1);
    insertIntoTrie(root, word2);
    insertIntoTrie(root, word3);
    insertIntoTrie(root, word4);
    
    // string prefix = "bal";
    // vector<string> ans;
    // findWordWithPrefix(root, prefix, ans);
    // for(int i=0; i<ans.size(); i++){
    //     string str = prefix + ans[i];
    //     ans[i] = str;
    //     cout<<ans[i]<<endl;
    // }

    string prefix = "bal";
    vector<vector<string>> ans = getSuggestions(root, prefix);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}