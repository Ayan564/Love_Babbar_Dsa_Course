#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constractor
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

// print the linked list
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// length of a linked list
int getlength(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp){
        length++;
        temp = temp->next;
    }
    return length;
}

// returns head of the new linked list after insertion
Node* insertAtHead(int value, Node* &head, Node* &tail){

    // LL is empty -> when head and tail both are NULL
    // This means this is the first node
    if(head == NULL && tail == NULL){
        // step 1: Create a new node
        Node* newNode = new Node(value);

        // step 2: head ko new node pe lagao
        head = newNode;

        // step 3: tail ko new node pe lagao
        tail = newNode;
    }
    // if LL is not empty
    else{
        // step 1: Create a new node
        Node* newNode = new Node(value);

        // step 2:
        newNode-> next = head;

        // step 3:
        head = newNode;
    }
    return head;
}
// returns head of the new linked list after insertion
Node* insertAtTail(int value, Node* &head, Node* &tail){

    // LL is empty -> when head and tail both are NULL
    // This means this is the first node
    if(head == NULL && tail == NULL){
        // step 1: Create a new node
        Node* newNode = new Node(value);

        // step 2: head ko new node pe lagao
        head = newNode;

        // step 3: tail ko new node pe lagao
        tail = newNode;
    }
    // if LL is not empty
    else{
        // step 1: Create a new node
        Node* newNode = new Node(value);

        // step 2:
        tail -> next = newNode;

        // step 3:
        tail = newNode;
    }
    return head;
}

// insert at any position of a linked list
Node* insertAtAnyPosition(int position, int value, Node* &head, Node* tail){
    int length = getlength(head);
    if(position == 1){
        insertAtHead(value, head, tail);
    }
    else if(position == length+1){
        insertAtTail(value, head, tail);
    }
    else{
        Node* temp = head;
        for(int i=1; i<position-1; i++){
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

// linear search in the linked list
bool linearSearch(int target, Node* head){
    Node* temp = head;
    while(temp){
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteNode(int position, Node* &head, Node* &tail){
    // if LL is empty -> can't delete anything
    if(head == NULL && tail == NULL){
        cout << "No Node to Delete" << endl;
        return;
    }
    // single Node in LL
    if(head == tail){
        Node* temp = head;
        head == NULL;
        tail == NULL;
        delete temp;
        return;
    }
    // have multiple node inside linked list
    else{
        // delete the first node
        if(position == 1){
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        // delete any other position
        else{
            Node* temp = head;
            for(int i=1; i<position-1; i++){
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            return;
        }
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    // LL is empty
    head = insertAtHead(10, head, tail);
    print(head);
    // 10 -> NULL
    head = insertAtHead(20, head, tail);
    print(head);
    // 20 -> 10 -> NULL
    head = insertAtHead(30, head, tail); 
    print(head);
    // 30 -> 20 -> 10 -> NULL


    head = insertAtTail(40, head, tail); 
    print(head);
    // 30 -> 20 -> 10 -> 40 -> NULL
    head = insertAtTail(30, head, tail); 
    print(head);
    // 30 -> 20 -> 10 -> 40 -> 30 -> NULL
    head = insertAtTail(20, head, tail); 
    print(head);
    // 30 -> 20 -> 10 -> 40 -> 30 -> 20 -> NULL


    head = insertAtAnyPosition(4, 200, head, tail);
    print(head);
    // 30 -> 20 -> 10 -> 200 -> 40 -> 30 -> 20 -> NULL
    head = insertAtAnyPosition(1, 300, head, tail);
    print(head);
    // 300 -> 30 -> 20 -> 10 -> 200 -> 40 -> 30 -> 20 -> NULL
    head = insertAtAnyPosition(9, 400, head, tail);
    print(head);
    // 300 -> 30 -> 20 -> 10 -> 200 -> 40 -> 30 -> 20 -> 400 -> NULL

    cout << linearSearch(3000, head) << endl;

    deleteNode(3, head, tail);
    print(head);
    // 300 -> 30 -> 10 -> 200 -> 40 -> 30 -> 20 -> 400 -> NULL
    
    deleteNode(1, head, tail);
    print(head);
    // 30 -> 10 -> 200 -> 40 -> 30 -> 20 -> 400 -> NULL

    deleteNode(7, head, tail);
    print(head);
    // 30 -> 10 -> 200 -> 40 -> 30 -> 20 -> NULL


    return 0;
}