#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int value){
            this->data = value;
            left = NULL;
            right = NULL;
        }
};


Node* createTree(){
    cout << "Enter the value for node: " << endl;
    int value;
    cin >> value;

    if(value == -1){
        return NULL;
    }
    else{
        // valid value
        Node* root = new Node(value);
        // 1 case mane solve kar liya baki recursion dekh lega
        cout << "Adding left child for " << value << endl;
        root->left = createTree();
        cout << "Adding right child for " << value << endl;
        root->right = createTree();
        return root;
    }
}

void preOrederTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // NLR
    cout << root->data << " ";
    preOrederTraversal(root->left);
    preOrederTraversal(root->right);
}

void inOrederTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // LNR
    preOrederTraversal(root->left);
    cout << root->data << " ";
    preOrederTraversal(root->right);
}

void postOrederTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // LRN
    preOrederTraversal(root->left);
    preOrederTraversal(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root;
    root = createTree();
    cout << "Printing root " << root->data << endl;
    preOrederTraversal(root);
    cout <<endl;
    inOrederTraversal(root);
    cout <<endl;
    postOrederTraversal(root);
    return 0;
}