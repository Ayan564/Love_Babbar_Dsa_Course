#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueueUsingStack(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void reverseQueueUsingRecursion(queue<int> &q){
    if(q.empty()){
        return;
    }
    // 1 case ma solve karunga
    int data = q.front();
    q.pop();
    // baki recursion samhal lega
    reverseQueueUsingRecursion(q);
    // backtracking
    q.push(data);
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // reverseQueueUsingStack(q);
    reverseQueueUsingRecursion(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}