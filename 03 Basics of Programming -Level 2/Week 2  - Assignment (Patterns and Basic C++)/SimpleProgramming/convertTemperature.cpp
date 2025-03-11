#include<iostream>
using namespace std;

void celsiusToFahrenheitAndKelvin(double celsius){
    double k = celsius + 273.15;
    double f = celsius * 1.80 +32.00;
    cout <<"The temperature in Kelvin = "<<k<<endl;
    cout <<"The temperature in Fahrenheit = "<<f<<endl;
}

int main(){
    double celsius;
    cout << "Enter the value of Celsius: ";
    cin >> celsius;
    celsiusToFahrenheitAndKelvin(celsius);
    return 0;
}