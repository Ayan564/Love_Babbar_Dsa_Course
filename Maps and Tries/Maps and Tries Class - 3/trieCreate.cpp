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

void insertIntoTrie(TrieNode* root, string word){
    // base case
    if(word.size() == 0){
        root->isTerminal = true;
        return;
    }

    // 1 case hum solve karenge
    char ch = word[0];
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
    insertIntoTrie(child, word.substr(1));
}

bool searchInTrie(TrieNode* root, string word){
    // base case
    if(word.size() == 0){
        return root->isTerminal;
    }

    // 1 case hum solve karenge
    char ch = word[0];
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
    bool recursionResult = searchInTrie(child, word.substr(1));
    return recursionResult;
}

void removeWord(TrieNode* root, string word){
    // base case
    if(word.size() == 0){
        root->isTerminal = false;
        return;
    }

    // 1 case hum solve karenge
    char ch = word[0];
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
    removeWord(child, word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');
    insertIntoTrie(root, "cover");
    insertIntoTrie(root, "car");
    insertIntoTrie(root, "care");
    insertIntoTrie(root, "snake");
    insertIntoTrie(root, "fivefoot");
    insertIntoTrie(root, "extreamlywell");
    insertIntoTrie(root, "coward");
    insertIntoTrie(root, "selfobsessed");
    insertIntoTrie(root, "tag");
    insertIntoTrie(root, "take");
    insertIntoTrie(root, "took");

    cout<<searchInTrie(root, "care")<<endl;
    removeWord(root, "care");
    cout<<searchInTrie(root, "care")<<endl;


    return 0;
}