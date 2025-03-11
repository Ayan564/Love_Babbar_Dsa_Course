#include<iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int capacity){
        arr = new int[capacity];
        size = capacity;
        top = -1;
    }

    void push(int val){
        if(top == size-1){
            cout << "Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top] = val;
        }
    }

    void pop(){
        if(top == -1){
            cout << "Stack Underflow"<<endl;
        }
            arr[top] = -1;
            top--;
    }

    int getsize(){
        return top+1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int getTop(){
        if(top == -1){
            cout << "There is no element at the top"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }

    void print(){
        cout << "Printing Stack" << endl;
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};


int main(){
    // int capacity;
    // cout << "Enter the capacity of the stack: ";
    Stack s(5);
    s.print();
    cout << s.getsize() << endl;
    s.push(10);
    s.print();
    s.push(20);
    s.print();
    s.push(30);
    s.print();
    s.push(40);
    s.print();
    s.push(50);
    s.print();
    // s.push(60);
    // s.print();
    cout << s.getTop() << endl;
    cout << s.getsize() << endl;
    s.pop();
    cout << s.getsize() << endl;
    s.print();
    return 0;
}