#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] <<" ";
    }
    cout << endl;
}

void printvv(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); ++i) {
    vector<int> &temp = v[i];
    int a = temp[0];
    int b = temp[1];
    cout << a << " " << b << endl;
  }
  cout << endl;
}

bool mycomp(int &a, int &b){
    return a>b; // this is decreasing order sorting
    // return a<b; // this is increasing order sorting
}

bool mycompfor1stIndex(vector<int> &a, vector<int> &b) {
  return a[1] > b[1]; // dsc order
  // return a[1] < b[1]; // asc order
}

int main(){
    // vector<int> v= {22, 44, 66, 33, 11, 99, 77, 88};
    // int size = v.size();
    // sort(v.begin(),v.end(),mycomp);
    // print(v);

    // vector of vector sorting
    vector<vector<int>> v;
    int n;
    cout << "Enter size:\n";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cout << "enter a, b" << endl;
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }

    cout << "Here are the Values" << endl;
    printvv(v);
    cout << "Sorted by 1st index" << endl;
    sort(v.begin(), v.end(), mycompfor1stIndex);
    printvv(v);
    return 0;
}