/*
Given a list of numbers that may has duplicate numbers, return all possible subsets

 Notice

Each element in a subset must be in non-descending order.
The ordering between two subsets is free.
The solution set must not contain duplicate subsets.
Have you met this question in a real interview? Yes
Example
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
Challenge 
Can you do it in both recursively and iteratively?
 */

class Solution {
public:
    /*
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        vector<int> curr;
        res.push_back(curr);
        for (int k = 1; k <= nums.size(); ++k) {
            for (int i = 0; i < nums.size() - k + 1; ++i) {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                curr.push_back(nums[i]);
                helper(nums, curr, res, i + 1, k - 1);
                curr.pop_back();
            }
        }
        return res;
    }

private:
    void helper(vector<int> &nums, vector<int> &curr, vector<vector<int>> &res,
            int idx, int k) {
        if (k == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            helper(nums, curr, res, i + 1, k - 1);
            curr.pop_back();
        }
    }
};
