#include<iostream>
using namespace std;

void rowWisePrint(int array[][3], int row, int col){
    cout << "Print the number row wise: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

bool linearSearch(int arr[][3], int col, int row, int target){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int array[3][3] = {{2,3,4},
                                  {5,6,7},
                                  {8,9,10}
                                };
    int rowSize = 3;
    int colSize = 3;
    rowWisePrint(array, rowSize, colSize);
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    bool ans = linearSearch(array, rowSize, colSize, target);
    if(ans == true){
        cout<<"Element is present in the 2D array."<<endl;
    }
    else{
        cout<<"Element is not present in the 2D array."<<endl;
    }
    return 0;
}