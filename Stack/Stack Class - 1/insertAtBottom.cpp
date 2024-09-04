#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s, int value){
    if(s.empty()){
        // insert value
        s.push(value);
        return;
    }
    // 1 case hum solve karenge baki recursion samha lega
    int topElement = s.top();
    s.pop();
    // baki recursion
    insertAtBottom(s,value);
    // backtrack
    s.push(topElement);
}

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int value = 13;
    insertAtBottom(s,value);

    // traverse the stack
    cout << "Print the stack:" << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout<<endl;

    return 0;
}