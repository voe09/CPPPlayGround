/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        if (k >= n) {
            int res = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    res += prices[i] - prices[i - 1];
                }
            }
            return res;
        }
        
        vector<vector<int>> global(n, vector<int>(k + 1, 0));
        vector<vector<int>> local(n, vector<int>(k + 1, 0));
        // dp
        // global[i][j] = max(global[i - 1][j], local[i][j]);
        // local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
        
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; ++j) {
                local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }
        return global[n - 1][k];
    }
};
