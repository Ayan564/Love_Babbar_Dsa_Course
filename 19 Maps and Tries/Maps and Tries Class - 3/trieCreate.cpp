#include<iostream>
#include<unordered_map>
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

int main(){
    TrieNode* root = new TrieNode('-');
    string word1 = "care";
    string word2 = "car";

    insertIntoTrie(root, word1);
    insertIntoTrie(root, word2);

    cout<<searchInTrie(root, word1)<<endl;
    removeWord(root, word1);
    cout<<searchInTrie(root, word2)<<endl;


    return 0;
}