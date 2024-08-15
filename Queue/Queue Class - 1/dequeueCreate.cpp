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

    void push_front(){

    }

    void push_back(){
        
    }

    void pop_front(){

    }

    void pop_back(){

    }
    
};

dequeueCreate::dequeueCreate(/* args */)
{
}

dequeueCreate::~dequeueCreate()
{
}


int main(){

    return 0;
}