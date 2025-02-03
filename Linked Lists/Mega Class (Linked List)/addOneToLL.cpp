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

void solve(Node* head, int& carry){
    if(!head) return;
    solve(head->next, carry);
    int sum = head->data + carry;
    int digit = sum % 10;
    carry = sum / 10;
    head->data = digit;
}

// add one to the linked list
Node* addOne(Node* head, int& carry){
    solve(head, carry);
    if(carry){
        Node* newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }
    return head;
}

int main(){
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    print(head);
    int carry = 2;
    head = addOne(head, carry);
    print(head);
    return 0;
}