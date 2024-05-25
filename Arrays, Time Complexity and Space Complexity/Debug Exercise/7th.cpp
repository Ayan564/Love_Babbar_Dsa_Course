#include<iostream>
using namespace std;

void sort0sand1s(int input[], int size) {
    int nextZero = 0;
    for (int i = 0; i < size; i++) {
        if (input[i] == 0) {
            // Swap input[i] and input[nextZero]
            int temp = input[nextZero];
            input[nextZero] = input[i];
            input[i] = temp;
            nextZero++;
        }
    }
}


int main(){
	int array[8] = {0,1,1,0,1,0,1,0};
	sort0sand1s(array,8);
	for(int i =0; i<8; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}