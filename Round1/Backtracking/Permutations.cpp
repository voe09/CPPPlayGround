/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        unordered_set<int> unused_nums;
        vector<int> perm;
        DFS(nums, unused_nums, perm, res);
        return res;
    }

private:
    void DFS(vector<int>& nums, unordered_set<int>& visited, vector<int>& perm, vector<vector<int>>& res) {
        if (visited.size() == nums.size() && !perm.empty()) {
            res.push_back(perm);
            return;
        }
        for (const auto& num : nums) {
            if (!visited.count(num)) {
                perm.push_back(num);
                visited.insert(num);
                DFS(nums, visited, perm, res);
                visited.erase(num);
                perm.pop_back();
            }
        }
    }
};
