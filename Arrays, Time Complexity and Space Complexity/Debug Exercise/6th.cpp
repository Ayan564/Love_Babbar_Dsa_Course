#include<iostream>
using namespace std;

int tripletSumToX(int input[], int size, int x){
	int triplets = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			for(int k=j+1; k<size; k++){
				if(input[i] + input[j] + input[k] == x){
					cout << input[i] <<" "<<input[j]<<" "<<input[k]<<endl;
					triplets++;
				}
			}
		}
	}
	return triplets;
}


int main(){
	int array[10] = {2,3,4,5,6,7,8,9,10,11};
	int size = 10;
	int ans = tripletSumToX(array,size,9);
	cout << ans <<endl;

	return 0;
}