// Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
// Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required.
#include <iostream>
#include <vector>
using namespace std;    
class Solution {
  public:
    vector<int> minPartition(int N) {
      vector<int> ans;
      vector<int> currency={1,2,5,10,20,50,100,200,500,2000};
      for(int i=currency.size()-1;i>=0;i--){
          int cnt=N/currency[i];
          if(cnt){
              ans.insert(ans.end(), cnt,currency[i]);   // fastest;  copies at once
              N=N%currency[i];
              if(N==1) {ans.push_back(1);break;}
          }
      }
      return ans;
    }
};
int main() {
    Solution sol;
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    vector<int> result = sol.minPartition(N);
    
    cout << "Minimum number of coins/notes required: ";
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;
    
    return 0;
}