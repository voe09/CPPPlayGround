/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n <= 0 || k <= 0 || k > n) return res;
        vector<int> comb;
        DFS(1, n, k, comb, res);
        return res;
    }

private:
    void DFS(int start, int n, int k, vector<int>& comb, vector<vector<int>>& res) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i <= n; ++i) {
            comb.push_back(i);
            DFS(i + 1, n, k, comb, res);
            comb.pop_back();
        }
    }
};
