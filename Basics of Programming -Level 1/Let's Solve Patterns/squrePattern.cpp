#include<iostream>
int main(){
    int n;
    std::cout<<"Enter the row number: ";
    std::cin>>n;
    for (int row =0; row<n; row++){
        for(int col=0; col<n; col++){
        std::cout<<"* ";
        }
        std::cout<<std::endl;
    }
    return 0;
}