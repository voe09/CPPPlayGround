/*
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> sum;
        DFS(candidates, target, 0, sum, res);
        return res;
    }

private:
    void DFS(vector<int>& candidates, int target, int start, vector<int>& sum, vector<vector<int>>& res) {
        if (target == 0 && !sum.empty()) {
            res.push_back(sum);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            sum.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i + 1, sum, res);
            sum.pop_back();
        }
        return;
    }
};
