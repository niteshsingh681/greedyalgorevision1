//2410. Maximum Matching of Players With Trainers
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int i = 0, j = 0, matches = 0;
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                matches++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return matches;
    }   

};
int main() {
    Solution sol;
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 6};
    
    int result = sol.matchPlayersAndTrainers(players, trainers);
    
    cout << "Maximum number of matches: " << result << endl;
    
    return 0;
}