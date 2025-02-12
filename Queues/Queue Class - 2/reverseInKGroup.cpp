#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseInKGroup(queue<int> &q, int k){
    int n = q.size();
    if(n < k){
        return;
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
    reverseInKGroup(q, k);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}