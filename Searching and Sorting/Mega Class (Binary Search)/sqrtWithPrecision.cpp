#include<iostream>
using namespace std;

int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long int mid = s+(e-s)/2;
        int ans = -1;

        while(s<=e){
            long long int prod = mid*mid;
            if(prod == x){
                return mid;
            }
            if(prod < x){
                //store and compute
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
}

double myPrecisionSqrt(int n){
    double sqrt = mySqrt(n);
    int precision = 9;
    double step = 0.1;
    while(precision--){
        double j = sqrt;
        while(j*j <= n){
            sqrt =j;
            j += step;
        }
        step /= 10;
    }
    return sqrt;
}

double bsPrecision(int n){
        double s = 0;
        double e = n;
        double mid = s+(e-s)/2;
        double ans = -1;

        while((e-s) >= 0.0000000001){
            double prod = mid*mid;
            if(prod == n){
                return mid;
            }
            if(prod < n){
                //store and compute
                ans = mid;
                s = mid;
            }
            else{
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        return ans;
}

int main(){
    int n =63;
    double ans = myPrecisionSqrt(n);
    printf("Sqrt is: %.9f\n",ans);
    ans = bsPrecision(n);
    printf("Sqrt is: %.9f\n",ans);
    return 0;
}