class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return res;
    }
};