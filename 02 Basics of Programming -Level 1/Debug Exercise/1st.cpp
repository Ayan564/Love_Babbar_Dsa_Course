#include<iostream>
using namespace std;

int main() {
	char c;
    cin>>c;
    // Error is the OR( || ) condition
    // if('a'<=c || c<= 'z'){
    //     cout<<0;
    // }
	// else if('A'<=c || c<= 'Z'){
    //     cout<<1;
    // }
    // else{
    //     cout<<-1;
    // }

    // Require AND ( && ) operator
    
    if('a'<=c && c<= 'z'){
        cout<<0;
    }
	else if('A'<=c && c<= 'Z'){
        cout<<1;
    }
    else{
        cout<<-1;
    }
}