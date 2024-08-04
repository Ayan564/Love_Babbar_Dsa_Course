#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int topElement = s.top();
    s.pop();

    insertAtBottom(s, val);
    s.push(topElement);
}

void reverseStack(stack<int>& s){
    if(s.empty()){
        return;
    }
    // 1 case hum solve karenge baki recursion samha lega
    int topElement = s.top();
    s.pop();

    // baki recursion
    reverseStack(s);

    // jab wapas aunga
    insertAtBottom(s, topElement);

}

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);

    // traverse the stack
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout<<endl;

    return 0;
}