#include<iostream>
using namespace std;

class KQueues{
    int n, k, freeSpot;
    int *arr, *front, *rear, *next;
    public:
    KQueues(int _n, int _k): n(_n), k(_k), freeSpot(0){
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        for(int i=0; i<k; i++){
            front[i] = rear[i] = -1;
        }
        for(int i=0; i<n-1; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    // push an element in the queue
    bool push(int X, int qi){
        if(freeSpot == -1){
            cout<<"Queue Overflow\n";
            return false;
        }
        int index = freeSpot;
        freeSpot = next[index];
        if(front[qi] == -1){
            front[qi] = index;
        }else{
            next[rear[qi]] = index;
        }
        next[index] = -1;
        rear[qi] = index;
        arr[index] = X;
        return true;
    }

    // pop an element from the queue
    int pop(int qi){
        if(front[qi] == -1){
            cout<<"Queue Underflow\n";
            return -1;
        }
        int index = front[qi];
        front[qi] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }

    // print the queue
    void print(){
        for(int i=0; i<k; i++){
            cout<<"Queue "<<i<<": ";
            for(int j=front[i]; j!=-1; j=next[j]){
                cout<<arr[j]<<" ";
            }
            cout<<endl;
        }
    }

    ~KQueues(){
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main(){
    KQueues kq(10, 3);
    kq.push(15, 2);
    kq.print();
    kq.push(45, 2);
    kq.print();
    kq.push(17, 1);
    kq.print();
    kq.push(49, 1);
    kq.print();
    kq.push(39, 1);
    kq.print();
    kq.push(11, 0);
    kq.print();
    kq.push(9, 0);
    kq.print();
    kq.push(7, 0);
    kq.print();
    cout<<kq.pop(2)<<endl;
    kq.print();

    return 0;
}