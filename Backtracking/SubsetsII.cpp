/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        DFS(nums, 0, subset, res);
        return res;
    }

private:
    void DFS(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& res) {
        if (start > nums.size()) return;
        res.push_back(subset);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            DFS(nums, i + 1, subset, res);
            subset.pop_back();
        }
    }
};
