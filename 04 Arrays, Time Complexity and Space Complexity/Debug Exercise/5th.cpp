#include<iostream>
using namespace std;

int pairSumToX(int input[], int size, int x){
	int pairs = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(input[i] + input[j] == x){
				pairs++;
				cout<<input[i] <<" "<<input[j]<<endl;
			}
		}
	}
	return pairs;
}

int main(){
	int array[6] = {11,22,33,44,55,66};
	int size = 6;
	int ans = pairSumToX(array,size,44);
	cout << ans <<endl;
	return 0;
}