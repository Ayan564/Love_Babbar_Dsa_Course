#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    stack<char> s;
    string name = "ayanmaity";
    cout<< "Print the name before: " << name << endl;
    for(int i=0; i<name.length(); i++){
        char ch = name[i];
        s.push(ch);
    }
    cout<< "Print the name after: ";
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    return 0;
}