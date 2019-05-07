/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Note: You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 */

// TLE
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int res = 0;
        DFS(coins, 0, amount, res);
        return res;
    }

private:
    void DFS(vector<int>& coins, int start, int amount, int& res) {
        if (amount == 0) {
            ++res;
            return;
        }
        if (amount < 0) return;

        for (int i = start; i < coins.size(); ++i) {
            DFS(coins, i, amount - coins[i], res);
        }
        return;
    }
};

// 转移方程: dp[i] = Σdp[i - coins[j]]; 表示 总额为i时的方案数 = 总额为i-coins[j]的方案数的加和.

// 下面这个loop求的是permutations
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.empty()) return 0;
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // Initialize
        for (int i = 1; i < amount; ++i) {
            for (const auto& coin : coins) {
                if (i - coin >= 0) {
                    dp[i] += dp[i - coin];
                }
            }
        }
        return dp[amount];
    }
};

// 调换loop后就是题目所求
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.empty() && amount == 0) return 1;
        if (coins.empty()) return 0;
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (const auto& coin : coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i - coin >= 0) {
                    dp[i] += dp[i - coin];
                }
            }
        }
        return dp[amount];
    }
};
