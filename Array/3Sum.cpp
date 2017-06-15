/*
Given an array S of n integers, are there elements a, b, c in S such that 
a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res; 
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            vector<pair<int, int>> tmp = twoSum(i, nums);
            if (tmp.size() != 0) {
                for (auto &pair: tmp) {
                    res.push_back({nums[i], pair.first, pair.second});
                }
            }
        }
        return res;
    }

private:
    vector<pair<int, int>> twoSum(int target_idx, vector<int>& nums) {
        vector<pair<int, int>> res;
        int begin = target_idx + 1;
        int end = nums.size() - 1;
        while (begin < end) {
            if (begin != target_idx + 1 && nums[begin] == nums[begin - 1]) {
                begin += 1;
                continue;
            }
            if (end != nums.size() - 1 && nums[end] == nums[end + 1]) {
                end -= 1;
                continue;
            }
            if (nums[begin] + nums[end] > -nums[target_idx]) {
                end -= 1;
            } else if (nums[begin] + nums[end] < -nums[target_idx]) {
                begin += 1;
            } else {
                res.push_back(make_pair(nums[begin], nums[end]));
                begin += 1;
                end -= 1;
            }
        }
        return res;
    }
};

/*
Given an array S of n integers, find three integers in S 
such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input 
would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int res = numeric_limits<int>::min();
        for (int i = 0; i < nums.size() - 2; ++i) {
            int tmp = twoSumClosest(i, nums, target - nums[i]);
            if (std::abs(tmp + nums[i] - target) < std::abs(res - target))
                res = tmp + nums[i];
        }
        return res;
    }

private:
    int twoSumClosest(int current_idx, vector<int>& nums, int target) {
        int res = numeric_limits<int>::min();
        int begin = current_idx + 1, end = nums.size() - 1;
        while (begin < end) {
            if (std::abs(nums[begin] + nums[end] - target) < std::abs(res - target))
                res = nums[begin] + nums[end];
            if (nums[begin] + nums[end] > target) {
                end -= 1;
            } else if (nums[begin] + nums[end] < target) {
                begin += 1;
            } else {
                return nums[begin] + nums[end];
            }
        }
        return res;
    }
};
