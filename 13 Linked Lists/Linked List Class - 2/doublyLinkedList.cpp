#include<iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    //constractor
    Node(int value){
        this->prev = NULL;
        this-> data = value;
        this->next = NULL;
    }
};

// print forward in the linked list
void print(Node* head){
    Node* temp = head;
    cout << "Print forward: ";
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// print backword in the linked list
void printb(Node* tail){
    Node* temp = tail;
    cout << "Print backward: ";
    while(temp){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// length of the doubly linked list
int getlength(Node* &head){
    Node* temp = head;
    int length = 0;
    while (temp)
    {
        length++;
        temp = temp-> next;
    }
    return length;
}

void insertAtHead(int value, Node* &head, Node* &tail){
    // LL is empty -> when head and tail both are NULL
    // This means this is the first node
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }

    // is LL is not empty
    else{
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(int value, Node* &head, Node* &tail){
    // DLL is empty -> when head and tail both are NULL
    // This means this is the first node
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }

    // if DLL is not empty
    else{
        Node* newNode = new Node(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// insert at any position of a doubly linked list
void insertAtAnyPosition(int position, int value, Node* &head, Node* &tail){
    int length = getlength(head);
    // insert at left most end
    if(position == 1){
        insertAtHead(value, head, tail);
    }
    // insert at right most end
    else if(position == length+1){
        insertAtTail(value, head, tail);
    }
    // insert at any middle position
    else{
        Node* temp = head;
        for(int i=1; i<position-1; i++){
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        Node* forward = temp-> next;
        temp->next = newNode;
        newNode-> prev = temp;
        newNode->next = forward;
        forward->prev = newNode;
    }
}

// search in a doubly linked list
bool searchElement(Node* head, int target){
    Node* temp =head;
    while (temp)
    {
        if(temp-> data == target){
            return true;
        }
        temp = temp-> next;
    }
    return false;
}

// delete node in doubly ilnked list
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
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
            return;
        }

        // delete the last node
        else if(position == getlength(head)){
            Node* temp = tail;
            tail = temp->prev;
            temp->prev = NULL;
            tail->next = NULL;
            delete temp;
            return;
        }

        // delete any other position
        else{
            Node* backward = head;
            for(int i=1; i<position-1; i++){
                backward = backward->next;
            }
            Node* current = backward->next;
            Node* forward = current->next;
            backward->next = forward;
            forward-> prev = backward;
            current->prev = NULL;
            current->next = NULL;
            delete current;
            return;
        }
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;


    // insertAtHead(10, head, tail);
    // print(head);
    // // 10 -> NULL
    // printb(tail);
    // // 10 -> NULL

    // insertAtHead(20, head, tail);
    // print(head);
    // // 20 -> 10 -> NULL
    // printb(tail);
    // // 10 -> 20 -> NULL

    // insertAtHead(30, head, tail);
    // print(head);
    // // 30 -> 20 -> 10 -> NULL
    // printb(tail);
    // // 10 -> 20 -> 30 -> NULL

    insertAtTail(10, head, tail);
    print(head);
    // 10 -> NULL
    printb(tail);
    // 10 -> NULL

    insertAtTail(20, head, tail);
    print(head);
    // 10 -> 20 -> NULL
    printb(tail);
    // 20 -> 10 -> NULL

    insertAtTail(30, head, tail);
    print(head);
    // 10 -> 20 -> 30 -> NULL
    printb(tail);
    // 30 -> 20 -> 10 -> NULL

    insertAtAnyPosition(1,100, head, tail);
    print(head);
    // 100 -> 10 -> 20 -> 30 -> NULL
    printb(tail);
    // 30 -> 20 -> 10 -> 100 -> NULL

    insertAtAnyPosition(5, 200, head, tail);
    print(head);
    // 100 -> 10 -> 20 -> 30 -> 200 -> NULL
    printb(tail);
    // 200 -> 30 -> 20 -> 10 -> 100 -> NULL

    insertAtAnyPosition(3, 300, head, tail);
    print(head);
    // 100 -> 10 -> 300 -> 20 -> 30 -> 200 -> NULL
    printb(tail);
    // 200 -> 30 -> 20 -> 300 -> 10 -> 100 -> NULL

    cout << searchElement(head, 10000) << endl;

    deleteNode(1,head,tail);
    print(head);
    // 10 -> 300 -> 20 -> 30 -> 200 -> NULL
    printb(tail);
    // 200 -> 30 -> 20 -> 300 -> 10 -> NULL

    deleteNode(5,head,tail);
    print(head);
    // 10 -> 300 -> 20 -> 30 -> NULL
    printb(tail);
    // 30 -> 20 -> 300 -> 10 -> NULL

    deleteNode(2,head,tail);
    print(head);
    // 10 -> 20 -> 30 > NULL
    printb(tail);
    // 30 -> 20 -> 10 -> NULL

    return 0;
}