
#include<iostream>
using namespace std;

class circulerQueue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    circulerQueue(int size){
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void push(int val){
        // overflow condition
        if((front == 0 && rear == size-1) || rear == front-1){
            cout<<"Queue is full"<<endl;
            return;
        }
        // push the first element
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        // circuler nature
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }
        // normal push
        else{
            rear++;
            arr[rear] = val;
        } 
    }

    void pop(){
        // underflow condition
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        // single element
        else if(front == rear){
            arr[front] = -1;
            front = rear = -1;
        }
        // circuler nature
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        }
        // normal pop
        else{
            arr[front] = -1;
            front++;
        }
    }

    int getFront(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(rear == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[rear];
    }

    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        }
        else if(rear > front){
            return rear-front+1;
        }
        return size-front+rear+1;
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    }

    void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    circulerQueue q(5);
    q.push(1);
    q.print();
    q.push(2);
    q.print();
    q.push(3);
    q.print();
    q.push(4);
    q.print();
    q.push(5);
    q.print();
    q.push(6);
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.push(6);
    q.print();
    cout  << q.getSize() << endl;

    return 0;
}