//860. Lemonade Change
#include <iostream>
#include <vector>       
using namespace std;
class Solution {
  public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<int> bills = {5, 50, 5, 10, 50}; // Example input
    bool result = sol.lemonadeChange(bills);
    
    if (result) {
        cout << "Yes, we can provide change for all customers." << endl;
    } else {
        cout << "No, we cannot provide change for all customers." << endl;
    }
    
    return 0;
}