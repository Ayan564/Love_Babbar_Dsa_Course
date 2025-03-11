#include<iostream>
int main(){
    int n;
    std::cout<<"Enter the row number: ";
    std::cin>>n;
    for (int row =0; row<n; row++){
        for(int col=0; col<n-row; col++){
        std::cout<<col+1<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}