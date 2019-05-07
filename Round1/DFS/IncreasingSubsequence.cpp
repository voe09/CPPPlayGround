/*
Given an integer array, your task is to find all the different possible increasing
subsequences of the given array, and the length of an increasing subsequence should
be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be
considered as a special case of increasing sequence.
 */

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        vector<int> sub;
        DFS(nums, sub, 0, res);
        return res;
    }

private:
    void DFS(vector<int>& nums, vector<int>& sub, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (sub.empty()) {
                sub.push_back(nums[i]);
                DFS(nums, sub, i + 1, res);
                sub.pop_back();
            } else {
                if (nums[i] >= sub.back()) {
                    if (i > start && nums[i] == nums[i - 1]) continue;
                    sub.push_back(nums[i]);
                    if (sub.size() >= 2) res.push_back(sub);
                    DFS(nums, sub, i + 1, res);
                    sub.pop_back();
                }
            }
        }
    }
};


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        helper(nums, 0, out, res);
        return res;
    }
    void helper(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() >= 2) res.push_back(out);
        unordered_set<int> st;
        for (int i = start; i < nums.size(); ++i) {
            if (!out.empty() && out.back() > nums[i] || st.count(nums[i])) continue; // array不是有序的
            out.push_back(nums[i]);
            st.insert(nums[i]);
            helper(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};



class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        helper(nums, 0, out, res);
        return res;
    }
    void helper(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() >= 2) res.push_back(out);
        unordered_set<int> st;
        for (int i = start; i < nums.size(); ++i) {
            if (!out.empty() && out.back() > nums[i] || st.count(nums[i])) continue;
            out.push_back(nums[i]);
            st.insert(nums[i]);
            helper(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};
