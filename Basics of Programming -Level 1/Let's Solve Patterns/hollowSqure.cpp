#include<iostream>
int main(){
    int length;
    std::cout<<"Enter the row number: ";
    std::cin>>length;
    for (int row =0; row<length; row++){
        for(int col=0; col<length; col++){
        if(row == 0 || row == length-1){
            std::cout<<"* ";
        }
        else{
            if(col == 0 || col == length-1){
                std::cout<<"* ";
            }
            else{
                std::cout<<"  ";
            }
        }
     }
        std::cout<<std::endl;
    }
    return 0;
}