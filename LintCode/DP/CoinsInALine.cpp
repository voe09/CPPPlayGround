/*
There are n coins in a line. Two players take turns to take one or two coins
from right side until there are no more coins left. The player who take the 
last coin wins.

Could you please decide the first play will win or lose?

Have you met this question in a real interview? Yes
Example
n = 1, return true.

n = 2, return true.

n = 3, return false.

n = 4, return true.

n = 5, return true.

Challenge 
O(n) time and O(1) memory
 */

class Solution {
public:
    /*
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        return firstWillWin(n, true);
        // return n % 3;
    }

private:
    bool firstWillWin(int n, bool first) {
        if (n == 0 && !first) return true;
        else if (n == 0 && first) return false;
        if (first) {
            return firstWillWin(n - 1, !first) || firstWillWin(n - 2, !first);
        } else {
            return firstWillWin(n - 1, !first) && firstWillWin(n - 2, !first);
        }
    }
};
