/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        DFS(nums, 0, subset, res);
        return res;
    }

private:
    void DFS(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& res) {
        if (start > nums.size()) return;
        res.push_back(subset);

        for (int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            DFS(nums, i + 1, subset, res);
            subset.pop_back();
        }
    }
};
