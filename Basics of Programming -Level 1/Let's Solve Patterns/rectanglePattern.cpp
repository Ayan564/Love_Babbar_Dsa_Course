#include<iostream>
int main(){
    int length,width;
    std::cout<<"Enter the row number: ";
    std::cin>>length;
    std::cout<<"Enter the column number: ";
    std::cin>>width;
    for (int row =0; row<length; row++){
        for(int col=0; col<width; col++){
        std::cout<<"* ";
        }
        std::cout<<std::endl;
    }
    return 0;
}