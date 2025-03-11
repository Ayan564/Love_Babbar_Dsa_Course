#include<iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int n;
        int front;
        int rear;
    public:
        Queue(int size){
            arr = new int[size];
            n = size;
            front = -1;
            rear = -1;
        }

        void push(int val){
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

        void pop(){
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
                arr[front] = -1;
                front++;
            }
        }

        int getFront(){
            if(front == -1){
                cout << "Queue is empty" << endl;
            }
            else{
                return arr[front];
            }
        }

        int getRear(){
            if(rear == -1){
                cout << "Queue is empty" << endl;
            }
            else{
                return arr[rear];
            }
        }

        int getSize(){
            if(front == -1 && rear == -1){
                return 0;
            }
            return rear-front+1;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q.getSize() << endl;
    q.pop();
    cout << q.getSize() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;


    return 0;
}