#include<iostream>
#include<vector>
using namespace std;

void wavePrintColwise(vector<vector<int>> &v){
    int m = v.size();
    int n = v[0].size();
    for(int startCol=0; startCol<n; startCol++){
        // even no of column -> top to bottom
        if(!(startCol & 1)){
            for(int i=0; i<m; i++){
                cout<<v[i][startCol]<<" ";
            }
        }
        // odd no of column -> bottom to top
        else{
            for(int i=m-1; i>=0; i--){
                cout<<v[i][startCol]<<" ";
            }
        }
    }
    cout << endl;
}

void wavePrintRowwise(vector<vector<int>> &v){
    int m = v.size();
    int n = v[0].size();
    for(int startRow=0; startRow<m; startRow++){
        // even no of row -> left to right
        if(!(startRow & 1)){
            for(int i=0; i<n; i++){
                cout<<v[startRow][i]<<" ";
            }
        }
        // odd no of row -> right to left
        else{
            for(int i=n-1; i>=0; i--){
                cout<<v[startRow][i]<<" ";
            }
        }
    }
    cout << endl;
}

int main(){
    vector<vector<int>> v = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    wavePrintColwise(v);
    wavePrintRowwise(v);

    return 0;
}