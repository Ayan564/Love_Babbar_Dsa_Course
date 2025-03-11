#include<iostream>
#include<math.h>
using namespace std;

float areaOfCircle(float r){
    float area = 3.14 * r * r;
    return area;
}

int main(){
    float r = 0;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    float ans = areaOfCircle(r);
    cout << "The area of the circle is: "<<ans<<endl;
    return 0;
}