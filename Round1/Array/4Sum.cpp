/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> tmp = kSum(nums, target - nums[i], i, 3);
            for (auto& vec: tmp) {
                vec.push_back(nums[i]);
                res.push_back(vec);
            }
        }
        return res;
    }

private:
    vector<vector<int>> kSum(vector<int>& nums, int target, int current_idx, int k) {
        vector<vector<int>> res;
        if (nums.size() - current_idx - 1 < k) return res;
        if (k == 2) {
            int start = current_idx + 1;
            int end = nums.size() - 1;
            while (start < end) {
                if (start > current_idx + 1 && nums[start] == nums[start - 1]) {
                    start += 1;
                    continue;
                }
                if (end < nums.size() - 1 && nums[end] == nums[end + 1]) {
                    end -= 1;
                    continue;
                }
                if (nums[start] + nums[end] < target) {
                    start += 1;
                } else if (nums[start] + nums[end] > target) {
                    end -= 1;
                } else {
                    res.push_back({nums[start], nums[end]});
                    start += 1;
                    end -= 1;
                }
            }
            return res;
        } else {
            for (int i = current_idx + 1; i < nums.size() -  k + 1; ++i) {
                if (i > current_idx + 1 && nums[i] == nums[i - 1]) continue;
                vector<vector<int>> tmp = kSum(nums, target - nums[i], i, k - 1);
                for (auto& vec: tmp) {
                    vec.push_back(nums[i]);
                    res.push_back(vec);
                }
            }
            return res;
        }
    }
};
