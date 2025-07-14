/*678. Valid Parenthesis String
minOpen = 0 (fewest possible open parentheses).

maxOpen = 0 (most possible open parentheses).

Loop Through String:

'(' → Both minOpen and maxOpen increase by 1.

')' → Both minOpen and maxOpen decrease by 1 (minOpen cannot go below 0).

If maxOpen < 0, it means there are more closing parentheses than can be balanced → invalid.

'*' → Can act as '(' (maxOpen++), ')' (minOpen--), or nothing.

minOpen = max(minOpen - 1, 0) (cannot be negative).

maxOpen++ (since '*' could be '(').

Final Check:

If minOpen == 0, the string is valid (all open parentheses can be balanced).*/

#include <iostream>
#include <string>       
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen = max(minOpen - 1, 0);
                maxOpen--;
                if (maxOpen < 0) return false; // More ')' than '(' + '*'
            } else { // '*'
                minOpen = max(minOpen - 1, 0);
                maxOpen++;
            }
        }
        return minOpen == 0;
    }
};
int main() {
    Solution solution;
    string s = "(*))";
    if (solution.checkValidString(s)) {
        cout << "The string is a valid parentheses string." << endl;
    } else {
        cout << "The string is not a valid parentheses string." << endl;
    }
    return 0;
}