#include<iostream>
using namespace std;

class dequeueCreate
{
private:
    int *arr;
    int n;
    int front;
    int rear;
public:
    dequeueCreate(int size){
        arr = new int[size];
        n = size;
        front = -1;
        rear = -1;
    }

    void push_front(int val){
        // overflow of queue
            if(front == 0){
                cout <<"Overflow" << endl;
            }
            // first element insert
            else if(front == -1 && rear == -1){
                front++; rear++;
                arr[front] = val;
            }
            // normal insertion
            else{
                front--;
                arr[front] = val;
            }
    }

    void push_back(int val){
        // overflow of queue
            if(rear == n-1){
                cout <<"Overflow" << endl;
            }
            // first element insert
            else if(front == -1 && rear == -1){
                front++; rear++;
                arr[rear] = val;
            }
            // normal insertion
            else{
                rear++;
                arr[rear] = val;
            }
    }

    void pop_front(){
         // underflow of queqe
            if(front == -1 && rear == -1){
                cout << "Underflow" << endl;
            }
            // single element to delete
            else if(front == rear){
                arr[front] = -1;
                front = -1; rear = -1;
            }
            // normal deletion
            else{
                arr[front] = -1;
                front++;
            }
    }

    void pop_back(){
        // underflow of queqe
            if(front == -1 && rear == -1){
                cout << "Underflow" << endl;
            }
            // single element to delete
            else if(front == rear){
                arr[rear] = -1;
                front = -1; rear = -1;
            }
            // normal deletion
            else{
                arr[rear] = -1;
                rear--;
            }
    }
    
    void print(){
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    dequeueCreate dq(5);
    dq.push_front(1);
    dq.print();
    dq.push_front(2);
    dq.print();
    dq.push_back(3);
    dq.print();
    dq.push_back(4);
    dq.print();
    dq.push_front(5);
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_front();
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_front();
    dq.print();

    return 0;
}