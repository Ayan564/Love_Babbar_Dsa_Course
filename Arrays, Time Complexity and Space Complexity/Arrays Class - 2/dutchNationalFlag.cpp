#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void sortColors(vector<int>& nums) {
        int red=0, white=0, blue=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                red++;
            }
            if(nums[i] == 1){
                white++;
            }
            if(nums[i] == 2){
                blue++;
            }
        }
        fill(nums.begin(),nums.begin()+red,0);
        fill(nums.begin()+red,nums.begin()+red+white,1);
        fill(nums.begin()+red+white,nums.end(),2);
        cout <<"No of red = "<<red<<endl;
        cout <<"No of white = "<<white<<endl;
        cout <<"No of blue = "<<blue<<endl;
        cout<<"The sorted array is: ";
        for(int i=0; i<n; i++){
            cout<<nums[i] << " ";
        }
}


int main(){
      vector<int> array;
      array.push_back(2);
      array.push_back(0);
      array.push_back(2);
      array.push_back(1);
      array.push_back(1);
      array.push_back(0);
      sortColors(array);
      return 0;
}