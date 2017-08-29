/*
Say you have an array for which the ith element is the price of a given stock
on day i.

Design an algorithm to find the maximum profit. You may complete as many
transactions as you like (ie, buy one and sell one share of the stock multiple
times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell
the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
 */

/*
此题需要维护三个一维数组buy, sell，和rest。其中：

buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。

sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。

rest[i]表示在第i天之前最后一个操作是冷冻期，此时的最大收益。

buy[i]  = max(rest[i-1] - price, buy[i-1])
sell[i] = max(buy[i-1] + price, sell[i-1])
rest[i] = max(sell[i-1], buy[i-1], rest[i-1])

一个小技巧是如何保证[buy, rest, buy]的情况不会出现，这是由于buy[i] <= rest[i]，
即rest[i] = max(sell[i-1], rest[i-1])，这保证了[buy, rest, buy]不会出现。
另外，由于冷冻期的存在，我们可以得出rest[i] = sell[i-1]，这样，我们可以将上面三个递推式精简到两个：

buy[i]  = max(sell[i-2] - price, buy[i-1])
sell[i] = max(buy[i-1] + price, sell[i-1])
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for (int price : prices) {
            pre_buy = buy;
            buy = max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }
        return sell;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> buy(prices.size()), sell(prices.size()), coolDown(prices.size());
        buy[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            // Bought before or buy today.
            buy[i] = max(buy[i - 1], coolDown[i - 1] - prices[i]);
            // Sell today.
            sell[i] = buy[i - 1] + prices[i];
            // Sold before yesterday or sold yesterday.
            coolDown[i] = max(coolDown[i - 1], sell[i - 1]);
        }
        return max(coolDown[prices.size() - 1], sell[prices.size() - 1]);
    }
};
