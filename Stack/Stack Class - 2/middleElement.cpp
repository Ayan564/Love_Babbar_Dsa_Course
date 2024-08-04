#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>& s, int count){
    if(count == 0){
        cout << s.top() << endl;
        return;
    }
    // 1 case hum solve karenge baki recursion samha lega
    int topElement = s.top();
    s.pop();
    count--;

    // baki recursion
    printMiddle(s,count);

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

    int count = s.size()/2;
    printMiddle(s,count);

    // traverse the stack
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout<<endl;

    return 0;
}