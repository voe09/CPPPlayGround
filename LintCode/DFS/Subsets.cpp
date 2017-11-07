/*
Given a set of distinct integers, return all possible subsets.

 Notice

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Have you met this question in a real interview? Yes
Example
If S = [1,2,3], a solution is:

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
Challenge 
Can you do it in both recursively and iteratively?
 */

class Solution {
public:
    /*
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        res.push_back({});
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        vector<int> curr;
        for (int k = 1; k <= nums.size(); ++k) {
            for (int i = 0; i < nums.size(); ++i) {
                if (i != 0 && nums[i] == nums[i - 1]) continue;
                curr.push_back(nums[i]);
                helper(nums, curr, i + 1, k, res);
                curr.pop_back();
            }
        }
        return res;
    }

private:
    void helper(vector<int> &nums, vector<int> &curr, 
            int idx, int k, vector<vector<int>> &res) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            if (i != idx && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            helper(nums, curr, i + 1, res);
            curr.pop_back();
        }
    }
};
