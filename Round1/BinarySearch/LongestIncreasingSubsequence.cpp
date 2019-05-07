/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
Note that there may be more than one LIS combination, it is only necessary 
for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return 0;
        vector<int> dp(length, 0);
        dp[0] = 1;
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
                else
                    dp[i] = max(dp[i], 1);
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};


// Binary search solution.
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (const auto& num : nums) {
            insert(&LIS, num);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        int left = 0, right = LIS->size() - 1;
        auto comp = [](int x, int target) { return x >= target; };

        // Find the first index "left" which satisfies LIS[left] >= target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (comp((*LIS)[mid], target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // If not found, append the target.
        if (left == LIS->size()) {
            LIS->emplace_back(target);
        } else {
            (*LIS)[left] = target;
        }
    }
};
