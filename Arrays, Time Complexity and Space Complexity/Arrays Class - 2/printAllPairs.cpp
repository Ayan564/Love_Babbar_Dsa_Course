#include<iostream>
using namespace std;

// print all posible combination
void printPair1(int arr[], int size){
    int count =0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout <<"("<<i<<", "<<j<<")";
            count++;
        }
        cout<<endl;
    }
    cout<<"The no of pairs is: "<<count<<endl;
}

// print the upper triangle
void printPair2(int arr[], int size){
    int count =0;
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            cout <<"("<<i<<", "<<j<<")";
            count++;
        }
        cout<<endl;
    }
    cout<<"The no of pairs is: "<<count<<endl;
}

// print the upper triangle without the same vlue pairs
void printPair3(int arr[], int size){
    int count =0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            cout <<"("<<i<<", "<<j<<")";
            count++;
        }
        cout<<endl;
    }
    cout<<"The no of pairs is: "<<count<<endl;
}

// print the lower triangle
void printPair4(int arr[], int size){
    int count =0;
    for(int i=0; i<size; i++){
        for(int j=0; j<i; j++){
            cout <<"("<<i<<", "<<j<<")";
            count++;
        }
        cout<<endl;
    }
    cout<<"The no of pairs is: "<<count<<endl;
}

// print the lower triangle includes the same value pair
void printPair5(int arr[], int size){
    int count =0;
    for(int i=0; i<size; i++){
        for(int j=0; j<=i; j++){
            cout <<"("<<i<<", "<<j<<")";
            count++;
        }
        cout<<endl;
    }
    cout<<"The no of pairs is: "<<count<<endl;
}

// print all posible combination reverse
void printPair6(int arr[], int size){
    int count =0;
    for(int i=0; i<size; i++){
        for(int j=size-1; j>=0; j--){
            cout <<"("<<i<<", "<<j<<")";
            count++;
        }
        cout<<endl;
    }
    cout<<"The no of pairs is: "<<count<<endl;
}

// print the upper triangle reverse
void printPair7(int arr[], int size){
    int count =0;
    for(int i=0; i<size; i++){
        for(int j=size-1; j>i; j--){
            cout <<"("<<i<<", "<<j<<")";
            count++;
        }
        cout<<endl;
    }
    cout<<"The no of pairs is: "<<count<<endl;
}


int main(){
    int array[5] = {10,20,30,40,50};
    int size =5;
    printPair1(array,size);
    printPair2(array,size);
    printPair3(array,size);
    printPair4(array,size);
    printPair5(array,size);
    printPair6(array,size);
    printPair7(array,size);

    return 0;
}