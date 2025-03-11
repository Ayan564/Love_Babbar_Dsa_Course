#include<iostream>
using namespace std;

class NStacks{
    int *arr;
    int *top;
    int *next;
    int n, size, freeSpot;
public:
    NStacks(int _n, int _s): n(_n), size(_s){
        arr = new int[size];
        top = new int[n];
        next = new int[size];
        freeSpot = 0;
        for(int i = 0; i < n; i++){
            top[i] = -1;
        }
        for(int i = 0; i < size - 1; i++){
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }
    bool push(int X, int m){
        if(freeSpot == -1){
            cout << "Stack Overflow\n";
            return false;
        }
        int index = freeSpot;
        freeSpot = next[index];
        next[index] = top[m];
        top[m] = index;
        arr[index] = X;
        return true;
    }
    int pop(int m){
        if(top[m-1] == -1){
            cout << "Stack Underflow\n";
            return -1;
        }
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
    ~NStacks(){
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};
int main(){
    NStacks s(3, 10);
    cout << s.push(15, 1) << endl;
    cout << s.push(45, 1) << endl;
    cout << s.push(17, 2) << endl;
    cout << s.push(49, 2) << endl;
    cout << s.push(39, 3) << endl;
    cout << s.push(99, 3) << endl;
    cout << s.push(9, 1) << endl;
    cout << s.pop(1) << endl;

    return 0;
}