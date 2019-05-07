/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
 */

/*
典型的贪心法，如果一个孩子比另一个孩子的分高，我们只多给1块糖。我们可以先从左往右遍历，
确保每个孩子根他左边的孩子相比，如果分高，则糖要多1个，如果分比左边低，就只给一颗。
然后我们再从右往左遍历，确保每个孩子跟他右边的孩子相比，如果分高则糖至少多1个
（这里至少多1个的意思是，我们要取当前孩子手里糖的数量，和其右边孩子糖的数量加1，
两者的较大值）。
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n, 1);

        // Left to right
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }

        // right to left
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                dp[i] = max(dp[i + 1] + 1, dp[i]);
            }
        }

        int sum = accumulate(dp.begin(), dp.end(), 0);
        return sum;
    }
};
