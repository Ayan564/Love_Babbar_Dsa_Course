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

void transposeUsingArray(int arr[][3], int row, int col){
    int ans[100][100];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            ans[i][j] = arr[j][i];
        }
    }
    cout << "Transpose of the matrix is: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
void transposeInSameArray(int arr[][3], int row, int col){
        for(int i=0; i<row; i++){
        for(int j=i; j<col; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    cout << "Transpose of the matrix is: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int array[3][3] = {{10,11,12},{20,21,22},{31,32,33}};
    int rowSize = 3;
    int colSize = 3;
    rowWisePrint(array, rowSize, colSize);
    transposeUsingArray(array, rowSize, colSize);
    transposeInSameArray(array, rowSize, colSize);
    return 0;
}