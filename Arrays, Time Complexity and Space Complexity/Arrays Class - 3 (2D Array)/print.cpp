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
void colWisePrint(int array[][3], int row, int col){
    cout << "Print the number column wise: " << endl;
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            cout << array[j][i] << " ";
        }
        cout << endl;
    }
}
void diagonalWisePrint(int array[][3], int row, int col){
    cout << "Print the number of diagonal: " << endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         if ( i == j)
    //             cout << array[i][j] << " ";
    //     }
    // }
    for(int i=0; i<row; i++){
        cout << array[i][i] << " ";
    }
    cout<<endl;
}
void invertdiagonalWisePrint(int array[][3], int row, int col){
    cout << "Print the number of invert diagonal: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if ( i+j == col-1)
                cout << array[i][j] << " ";
        }
    }
}

int main(){
    int array[3][3] = {{2,3,4},{5,6,7},{8,9,10}};
    int rowSize = 3;
    int colSize = 3;
    int size = 3;
    // rowWisePrint(array, rowSize, colSize);
    // cout<<endl;
    // colWisePrint(array, rowSize, colSize);
    // cout<<endl;
    // diagonalWisePrint(array, rowSize, colSize);
    // cout<<endl;
    invertdiagonalWisePrint(array, rowSize, colSize);
    return 0;
}