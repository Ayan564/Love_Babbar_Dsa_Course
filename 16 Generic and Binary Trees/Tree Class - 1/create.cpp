#include<iostream>
#include<queue>
#include <deque> 
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
    inOrederTraversal(root->left);
    cout << root->data << " ";
    inOrederTraversal(root->right);
}

void postOrederTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // LRN
    postOrederTraversal(root->left);
    postOrederTraversal(root->right);
    cout << root->data << " ";
}

void leftToRightLevelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << current->data << " ";
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
    }
}

void rightToLeftLevelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << current->data << " ";
            if(current->right){
                q.push(current->right);
            }
            if(current->left){
                q.push(current->left);
            }
        }
    }
}

void zigzagLevelOrderTraversal(Node* root) {
    if (root == NULL) return;
    bool LtoRdir = true;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int width = q.size();
        vector<int> oneLevel(width); 
        for (int i = 0; i < width; i++) {
            Node* front = q.front(); q.pop();
            int index = LtoRdir ? i : width - i - 1;
            oneLevel[index] = front->data;
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        // Print the current level
        for (int val : oneLevel) {
            cout << val << " ";
        }
        cout << endl;
        LtoRdir = !LtoRdir;
    }
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
    cout <<endl;
    leftToRightLevelOrderTraversal(root);
    cout <<endl;
    rightToLeftLevelOrderTraversal(root);
    cout <<endl;
    zigzagLevelOrderTraversal(root);
    return 0;
}