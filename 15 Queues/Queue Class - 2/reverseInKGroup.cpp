#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseInKGroup(queue<int> &q, int k, int count){
    if(count >= k){
        stack<int> s;
        // fetch the first k elements from the queue and push them into the stack
        for(int i = 0; i < k; i++){
            s.push(q.front());
            q.pop();
        }
        // pop the elements from the stack and push them back into the queue
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        reverseInKGroup(q, k, count - k);
    }
    else{
        // if the remaining elements are less than k, then push them back into the queue
        for(int i = 0; i < count; i++){
            q.push(q.front());
            q.pop();
        }
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);

    int k = 3;
    int count = q.size(); // it tracks the size of the queue
    reverseInKGroup(q, k, count);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}