#include<iostream>
using namespace std;

int getQuotient(int dividend, int divisor){
    // search space -> (-ve dividend) to (+ve dividend)
    int s = 0;
    int e = dividend;
    int mid = s+((e-s)>>1);
    int ans = -1;

    while(s <= e){
        if(divisor * mid == dividend){
            return mid;
        }
        if((divisor*mid) <dividend){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+((e-s)>>1);
    }
    return ans;
}

double getQuotientWithPrecision(int dividend, int divisor, int precision) {
    double quotient = getQuotient(dividend, divisor);
    double step = 0.1;

    for (int i = 0; i < precision; ++i) {
        while ((divisor * quotient) <= dividend) {
            quotient += step;
        }
        quotient -= step;
        step /= 10;
    }
    return quotient;
}

double getQuotientWithPrecisionBS(int dividend, int divisor) {
    double s = 0;
    double e = dividend;
    double mid = s + (e - s) / 2.0;
    double ans = 0;

    while ((e - s) > 0.0000000001) {
        double prod = divisor * mid;
        if (prod == dividend) {
            return mid;
        }
        if (prod < dividend) {
            ans = mid;
            s = mid;
        } 
        else {
            e = mid;
        }
        mid = s + (e - s) / 2.0;
    }
    return ans;
}

int main(){
    int dividend = -445;
    int divisor = -3;
    int precision = 5;

    double ans = getQuotientWithPrecision(abs(dividend),abs(divisor), precision);
    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
        ans = 0-ans;
    }
    cout <<"Quotient is: "<<ans<<endl;
    ans = getQuotientWithPrecision(abs(dividend),abs(divisor), precision);
    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
        ans = 0-ans;
    }
    cout <<"Quotient is: "<<ans<<endl;

    return 0;
}