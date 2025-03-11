#include<iostream>
#include<algorithm>
using namespace std;

void permutationSTL(string str){
    sort(str.begin(), str.end());
    do{
        cout << str << '\t';
    }while(next_permutation(str.begin(), str.end()));
}

void printPermutation(string &str, int i){
    // base case
    if(i >= str.length()){
        cout << str << '\t';
        return;
    }
    for(int j=i; j<str.length(); j++){
        swap(str[i], str[j]);
        printPermutation(str,i+1);
        //backtracking
        swap(str[i], str[j]);
    }
}

int main(){
    string str = "123";
    int i=0;
    // printPermutation(str,i);
    permutationSTL(str);
    return 0;
}