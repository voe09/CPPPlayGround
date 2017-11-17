/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 

Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
 

Examples: 
input: 1
output: 

[]
input: 37
output: 

[]
input: 12
output:

[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:

[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
 

这道题给了我们一个正整数n，让我们写出所有的因子相乘的形式，而且规定了因子从小到大的顺序排列，那么对于这种需要列出所有的情况的题目，通常都是用回溯法来求解的，由于题目中说明了1和n本身不能算其因子，那么我们可以从2开始遍历到n，如果当前的数i可以被n整除，说明i是n的一个因子，我们将其存入一位数组out中，然后递归调用n/i，此时不从2开始遍历，而是从i遍历到n/i，停止的条件是当n等于1时，如果此时out中有因子，我们将这个组合存入结果res中，参见代码如下：
 */

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        helper(n, 2, {}, res);
        return res;
    }
    void helper(int n, int start, vector<int> out, vector<vector<int>> &res) {
        if (n == 1) {
            if (out.size() > 1) res.push_back(out);
        } else {
            for (int i = start; i <= n; ++i) {
                if (n % i == 0) {
                    out.push_back(i);
                    helper(n / i, i, out, res);
                    out.pop_back();
                }
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(n, curr, 2, res);
        return res;
    }

private:
    void helper(int n, vector<int> &curr, int start, vector<vector<int>> &res) {
        if (n <= 1) {
            if (curr.size() > 1) {
                res.push_back(curr);
            }
            return;
        }

        for (int i = start; i < n; ++i) {
            if (n % i == 0) {
                curr.push_back(i);
                helper(n / i, curr, i, res);
                curr.pop_back();
            }
        }
    }
};
