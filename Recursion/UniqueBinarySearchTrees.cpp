/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time Limited Exceed
class Solution {
public:
    int numTrees(int n) {
        return numTree(1, n);
    }

private:
    int numTree(int start, int end) {
        int cnt = 0;
        if (start > end) return cnt;
        for (int i = start; i <= end; ++i) {
            int left = max(1, numTree(start, i - 1));
            int right = max(1, numTree(i + 1, end));
            cnt += left * right;
        }
        return cnt;
    }
};

// Correct Answer

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        //dp初始化
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                //如果左子树的个数为j，那么右子树为i - j - 1
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};
