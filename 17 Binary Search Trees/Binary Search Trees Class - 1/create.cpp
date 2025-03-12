#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buidBST(int val, Node* &root){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    else{
        if(val < root->data){
            root->left = buidBST(val, root->left);
        }else{
            root->right = buidBST(val, root->right);
        }
    }
    return root;
}

void createTree(Node* &root){
    cout <<"Enter the value for Node: ";
    int val;
    cin >> val;
    while(val != -1){
        buidBST(val, root);
        cout <<"Enter the value for Node: ";
        cin >> val;
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

void levelOrderTraversal(Node* root){
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

int getMin(Node* root){
    if(root == NULL){
        return -1;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int getMax(Node* root){
    if(root == NULL){
        return -1;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

void inOrederTraversalForMinMax(Node* root, vector<int> &inOrder){
    if(root == NULL){
        return;
    }
    inOrederTraversalForMinMax(root->left, inOrder);
    inOrder.push_back(root->data);
    inOrederTraversalForMinMax(root->right, inOrder);
}

pair<int, int> getMinMaxUsingInorderTraversal(Node* root){
    vector<int> inOrder;
    inOrder.clear();
    inOrederTraversalForMinMax(root, inOrder);
    return {inOrder[0], inOrder[inOrder.size()-1]};
}

bool searchInBST(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return searchInBST(root->left, key);
    }else{
        return searchInBST(root->right, key);
    }
}


int main(){
    Node* root = NULL;
    createTree(root);
    // 100 50 200 70 20 250 150
    cout << "Pre Order Traversal of the tree is: " << endl;
    preOrederTraversal(root);
    cout << endl;
    cout << "In Order Traversal of the tree is: " << endl;
    inOrederTraversal(root);
    cout << endl;
    cout << "Post Order Traversal of the tree is: " << endl;
    postOrederTraversal(root);
    cout << endl;
    cout << "Level Order Traversal of the tree is: " << endl;
    levelOrderTraversal(root);

    cout << "Minimum value in the tree is: " << getMin(root) << endl;
    cout << "Maximum value in the tree is: " << getMax(root) << endl;
    cout << "Minimum and Maximum value in the tree using Inorder Traversal is: " << getMinMaxUsingInorderTraversal(root).first << " " << getMinMaxUsingInorderTraversal(root).second << endl;

    int key;
    cout << "Enter the key to search in the tree: ";
    cin >> key;
    if(searchInBST(root, key)){
        cout << "Key is present in the tree" << endl;
    }else{
        cout << "Key is not present in the tree" << endl;
    }

    return 0;
}