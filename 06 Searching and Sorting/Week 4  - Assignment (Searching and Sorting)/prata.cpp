#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector<int>& ratings, int nP, int mid){
    int currP = 0; // initial cooked prata count
    for(int i=0; i<ratings.size(); i++){
        int R = ratings[i];
        int j = 1;
        int timeTaken = 0;

        while(true){
            if(timeTaken + j*R <= mid){
                ++currP;
                timeTaken += j*R;
                ++j;
            }
            else{
                break;
            }
        }
        if(currP >= nP){
            return true;
        }
    }
    return false;
}

int minTimeToCompleteOrder(vector<int>& ratings, int nP){
    int start = 0;
    int heighestRank = *max_element(ratings.begin(), ratings.end());
    int end = heighestRank * (nP * (nP + 1) / 2);
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(isPossibleSolution(ratings, nP, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int nP, nC;
        cin >> nP >> nC;
        vector<int> ratings;
        while(nC--){
            int rating;
            cin >> rating;
            ratings.push_back(rating);
        }
        cout << minTimeToCompleteOrder(ratings, nP) << endl;
    }

    return 0;
}