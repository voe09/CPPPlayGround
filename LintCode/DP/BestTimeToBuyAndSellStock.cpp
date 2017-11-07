/*
Say you have an array for which the ith element is the price of a given stock
on day i.

If you were only permitted to complete at most one transaction (ie, buy one and
sell one share of the stock), design an algorithm to find the maximum profit.

Have you met this question in a real interview? Yes
Example
Given array [3,2,3,1,2], return 1.
 */

class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int res = 0;
        int minVal = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < minVal) minVal = prices[i];
            res = max(res, prices[i] - minVal);
        }
        return res;
    }
};
