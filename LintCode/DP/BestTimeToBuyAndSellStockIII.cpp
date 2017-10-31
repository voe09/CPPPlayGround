/*
Say you have an array for which the ith element is the price of a given stock on
day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

 Notice

You may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).

Have you met this question in a real interview? Yes
Example
Given an example [4,4,6,1,1,4,2,5], return 6.
 */

// TLE
class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.empty()) return 0;
        int res = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            int curr = maxProfitOneTransaction(prices, 0, i)
                + maxProfitOneTransaction(prices, i, prices.size() - 1);
            res = max(res, curr);
        }
        return res;
    }

private:
    int maxProfitOneTransaction(vector<int> &prices, int start, int end) {
        int res = 0;
        int curr = prices[start];
        for (int i = start + 1; i <= end; ++i) {
            if (prices[i] < curr) {
                curr = prices[i];
            }
            else if (prices[i] > curr) {
                res = max(res, prices[i] - curr);
            }
        }
        return res;
    }
};


// DP
class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.size() <= 1) return 0;
        return maxProfit(prices, 2);
    }

private:
    int maxProfit(vector<int> &prices, int k) {
        int n = prices.size();
        vector<vector<int>> global (n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> local (n + 1, vector<int>(k + 1, 0));
        for (int i = 2; i <= n; ++i) {
            int diff = prices[i - 1] - prices[i - 2];
            for (int j = 1; j <= k; ++j) {
                local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }
        return global[n][k];
    }
};
