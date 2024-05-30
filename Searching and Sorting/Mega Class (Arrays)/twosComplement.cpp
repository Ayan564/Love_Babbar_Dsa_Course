#include<iostream>
#include<vector>
using namespace std;

vector<int> findComplement(vector<int> binary){
    int n = binary.size();
    vector<int> twosComplement(n, 0);
    //flip the bits of the input array(find one's complement)
    for(int i=0; i<n; i++){
        twosComplement[i] = binary[i] == 0 ? 1 : 0;
    }
    //add one to the fliped array to find two's complement
    int carry = 1;
    for(int i=twosComplement.size()-1; i>=0; i--){
        int sum = twosComplement[i] + carry;
        twosComplement[i] = sum%2;
        carry = sum/2;
    }
    return twosComplement;
}

int main(){

    vector<int> binary = {0,0,1,1,0,0};
    vector<int> twosComplement = findComplement(binary);
    for(int i=0; i<twosComplement.size(); i++){
        cout <<twosComplement[i] <<" ";
    }
    cout <<endl;
    return 0;
}