#include<iostream>
int main(){
    int n;
    std::cout<<"Enter the row number: ";
    std::cin>>n;
    for (int row =0; row<n; row++){
        for(int col=0; col<n-row; col++){
         if(row == 0 || row == n-1){
                std::cout<<"* ";
            }else{
                if(col == 0 || (row+col == n-1)){
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