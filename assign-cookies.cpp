//455. Assign Cookies
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie]) {
                child++;
            }
            cookie++;
        }
        return child;
    }   

};
 int main(){
    vector<int> g = {1, 2, 3}; // Children's greed factors
    vector<int> s = {1, 1}; // Cookie sizes
    Solution sol;
    int ans=sol.findContentChildren(g, s);
    cout << "Number of content children: " << ans << endl;


    return 0;
 }