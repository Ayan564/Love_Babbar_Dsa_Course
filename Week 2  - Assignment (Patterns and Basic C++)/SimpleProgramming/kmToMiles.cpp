#include<iostream>
using namespace std;

float kmToMiles(float km){
    float miles = 0.621371;
    km = km * miles;
    return km;
}

int main(){
    float km;
    cout << "Enter the distance in KM: ";
    cin >> km;
    float ans = kmToMiles(km);
    cout << "The calculated distance in Miles is: "<<ans<<endl;
    return 0;
}