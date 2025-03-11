#include<iostream>
using namespace std;

class deCirculerQueue{
    int *arr;
    int size;
    int front;
    int rear;
    
    public:
    deCirculerQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    void pushFront(int val){
        // overflow of queue
            if((front == 0 && rear == size-1) || (rear == front-1)){
                cout <<"Overflow" << endl;
            }
            // first element insert
            else if(front == -1 && rear == -1){
                front++; rear++;
                arr[rear] = val;
            }
            // circular insertion
            else if(front == 0 && rear != size-1){
                front = size-1;
                arr[front] = val;
            }
            // normal insertion
            else{
                front++;
                arr[front] = val;
            }
    }

    void pushBack(int val){
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

    void popFront(){
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

    void popBack(){
        // underflow of queqe
            if(front == -1 && rear == -1){
                cout << "Underflow" << endl;
            }
            // single element to delete
            else if(front == rear){
                arr[rear] = -1;
                front = -1; rear = -1;
            }
            // circular deletion
            else if(rear == 0){
                arr[rear] = -1;
                rear = size-1;
            }
            // normal deletion
            else{
                arr[rear] = -1;
                rear--;
            }
    }

    void print(){
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    deCirculerQueue q(5);
    q.pushFront(10);
    q.print();
    q.pushFront(20);
    q.print();
    q.pushBack(30);
    q.print();
    q.pushBack(40);
    q.print();
    q.pushBack(50);
    q.print();
    q.pushFront(60);
    q.print();
    q.popFront();
    q.print();
    q.popFront();
    q.print();
    q.popFront();
    q.print();
    q.popBack();
    q.print();
    q.popBack();
    q.print();
    q.popBack();
    


    return 0;
}