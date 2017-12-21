/*
There are n coins with different value in a line. Two players take turns to
take one or two coins from left side until there are no more coins left. The 
player who take the coins with the most value wins.

Could you please decide the first player will win or lose?

Example
Given values array A = [1,2,2], return true.

Given A = [1,2,4], return false.
 */

/*
 * dp[i]表示从i到end可取的最大钱数
1. 当我们只拿一个硬币values[i]时，那么对手有两种选择，拿一个硬币values[i+1]，
   或者拿两个硬币values[i+1] + values[i+2]
a) 当对手只拿一个硬币values[i+1]时，我们只能从i+2到end之间来取硬币，
   所以我们能拿到的最大硬币数为dp[i+2]
b) 当对手拿两个硬币values[i+1] + values[i+2]时，我们只能从i+3到end之间来取硬币，
   所以我们能拿到的最大硬币数为dp[i+3] 由于对手的目的是让我们拿较小的硬币，
   所以我们只能拿dp[i+2]和dp[i+3]中较小的一个，所以对于我们只拿一个硬币的情况，
  我们能拿到的最大钱数为values[i] + min(dp[i+2], dp[i+3])

2. 当我们拿两个硬币values[i] + values[i + 1]时，那么对手有两种选择，
   拿一个硬币values[i+2]，或者拿两个硬币values[i+2] + values[i+3]
a) 当对手只拿一个硬币values[i+2]时，我们只能从i+3到end之间来取硬币，
   所以我们能拿到的最大硬币数为dp[i+3]
b) 当对手拿两个硬币values[i+2] + values[i+3]时，我们只能从i+4到end之间来取硬币，
   所以我们能拿到的最大硬币数为dp[i+4]
   由于对手的目的是让我们拿较小的硬币，所以我们只能拿dp[i+3]和dp[i+4]中较小的一个，
   所以对于我们只拿一个硬币的情况，我们能拿到的最大钱数为
   values[i] + values[i + 1] + min(dp[i+3], dp[i+4])

综上所述，递推式就有了 
dp[i] = max(values[i] + min(dp[i+2], dp[i+3]), values[i] + values[i + 1] + min(dp[i+3], dp[i+4]))
这样当我们算出了dp[0]，知道了第一个玩家能取出的最大钱数，我们只需要算出总钱数，
然后就能计算出另一个玩家能取出的钱数，二者比较就知道第一个玩家能否赢了，参见代码如下：
 */


class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        if (values.size() <= 2) return true;
        int n = values.size();
        vector<int> dp (n + 1, 0);
        dp[n - 1] = values[n - 1];
        dp[n - 2] = values[n - 1] + values[n - 2];
        dp[n - 3] = values[n - 2] + values[n - 3];
        for (int i = n - 4; i >= 0; --i) {
            int w = values[i] + min(dp[i + 2], dp[i + 3]);
            int v = values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4]);
            dp[i] = max(w, v);
        }

        int sum = accumulate(values.begin(), values.end(), 0);
        return sum - dp[0] < dp[0];
    }
};


class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        if (values.size() <= 2) return true;
        int n = values.size(), sum = 0;
        vector<int> dp(n + 1, 0);
        dp[n - 1] = values[n - 1];
        dp[n - 2] = values[n - 2] + values[n - 1];
        dp[n - 3] = values[n - 3] + values[n - 2];
        for (int i = n - 4; i >= 0; --i) {
            dp[i] = max(values[i] + min(dp[i + 2], dp[i + 3]), 
                        values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4]));
        }
        for (int d : values) {
            sum += d;
        }
        return sum - dp[0] < dp[0];
    }
};
