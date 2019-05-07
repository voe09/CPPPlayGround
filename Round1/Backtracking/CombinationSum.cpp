/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) return res;
        vector<int> sum;
        DFS(candidates, target, 0, sum, res);
        return res;
    }

    void DFS(vector<int>& candidates, int target, int start, vector<int>& sum, vector<vector<int>>& res) {
        if (target == 0 && !sum.empty()) {
            res.push_back(sum);
            return;
        }
        
        if (target < 0) return;

        for (int i = start; i < candidates.size(); ++i) {
            sum.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i, sum, res);
            sum.pop_back();
        }
    }
};
