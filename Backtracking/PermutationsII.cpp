/*
Given a collection of numbers that might contain duplicates, 
return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        vector<bool> visited(nums.size(), false);
        vector<int> perm;
        sort(nums.begin(), nums.end());
        DFS(nums, perm, visited, res);
        return res;
    }

private:
    void DFS(vector<int>& nums, vector<int>& perm,
            vector<bool>& visited, vector<vector<int>>& res) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
                visited[i] = true;
                perm.push_back(nums[i]);
                DFS(nums, perm, visited, res);
                perm.pop_back();
                visited[i] = false;
            }
        }
    }
};
