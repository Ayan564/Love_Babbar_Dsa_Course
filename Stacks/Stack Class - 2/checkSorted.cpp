#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

bool checkSorted(stack<int>& s, int ele1){
    if(s.empty()){
        return true;
    }
    // 1 case hum solve karenge baki recursion samha lega
    int ele2 = s.top();
    s.pop();
   if(ele2 < ele1){
        bool ageKaAns = checkSorted(s, ele2);
        s.push(ele2);
        return ageKaAns;
   }
   else{
    s.push(ele2);
    return false;
   }
}

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(3);
    s.push(40);
    s.push(50);

    int element1 = INT_MAX;
    cout << checkSorted(s, element1) << endl;

    // traverse the stack
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout<<endl;

    return 0;
}