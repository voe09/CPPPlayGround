/*
Say you have an array for which the ith element is the price of a given
stock on day i.

Design an algorithm to find the maximum profit. You may complete as many
transactions as you like (ie, buy one and sell one share of the stock 
multiple times). However, you may not engage in multiple transactions 
at the same time (ie, you must sell the stock before you buy again).

Have you met this question in a real interview? Yes
Example
Given an example [2,1,2,0,1], return 2
 */

class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.empty()) return 0;
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};
