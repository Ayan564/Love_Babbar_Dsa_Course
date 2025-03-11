#include<iostream>
#include <iomanip>
using namespace std;
int main(){
    int a =10;
    int b = 3.2;
    float c = a/b;
    cout << fixed << setprecision(1) << c << endl;
    return 0;
}