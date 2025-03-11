#include<iostream>
#include<limits.h>
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

int findMin(int arr[][3], int col, int row){
    int min = INT_MAX;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] < min){
                min = arr[i][j];
            }
        }
    }
    return min;
}

int findMax(int arr[][3], int col, int row){
    int max = INT_MIN;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] > max){
                max = arr[i][j];
            }
        }
    }
    return max;
}

int main(){
    int array[3][3] = {{2,3,4},
                                  {5,6,7},
                                  {8,9,10}
                                };
    int rowSize = 3;
    int colSize = 3;
    rowWisePrint(array, rowSize, colSize);
    int min = findMin(array, rowSize, colSize);
    int max = findMax(array, rowSize, colSize);
    cout << "The minimum element is: " << min << endl;
    cout << "The maximum element is: " << max << endl;
    return 0;
}