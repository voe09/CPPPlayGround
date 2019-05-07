/*
Given a rod of length n inches and an array of prices that contains prices of
all pieces of size smaller than n. Determine the maximum value obtainable by
cutting up the rod and selling the pieces. For example, if length of the rod
is 8 and the values of different pieces are given as following, then the maximum
obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

Have you met this question in a real interview? Yes
Example
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
Given price = [1, 5, 8, 9, 10, 17, 17, 20], n = 8
Return 22 // by cutting in two pieces of lengths 2 and 6

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20
Given price = [3, 5, 8, 9, 10, 17, 17, 20], n = 8
Return 24 // by cutting in eight pieces of length 1
 */

class Solution {
public:
    /*
     * @param : the prices
     * @param : the length of rod
     * @return: the max value
     */
    int cutting(vector<int>& prices, int n) {
        // Write your code here
        if (n == 0) return 0;
        vector<int> dp (n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = prices[i - 1];
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], dp[i - j] + dp[j]);
            }
        }

        return dp[n];
    }
};
