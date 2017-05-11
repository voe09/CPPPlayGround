/*
 * Given an unsorted integer array, find the first missing positive integer.
 * For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.
 * Your algorithm should run in O(n) time and uses constant space.
 */

/* idea: kind of hash map, map positive integer A[i] to the position A[i -1]
 * After mapping, go through the vector again, find the one not fit
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            
            // swap condition:
            // 1. nums[i] is in the range
            // 2. nums[i] > 0
            // 3. the target is different
            while (nums[i] <= nums.size() && nums[i] > 0
                    && nums[nums[i] - 1] != nums[i]) {
                std::iter_swap(nums.begin() + i, nums.begin() + nums[i] - 1);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return nums.size() + 1;
    }
};
