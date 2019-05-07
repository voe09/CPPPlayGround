/*
Given an array of integers with possible duplicates, 
randomly output the index of a given target number. You can assume that 
the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space 
will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. 
// Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
 */

class Solution {
public:
    Solution(vector<int> nums): nums_(nums) {

    }

    int pick(int target) {
        int res;
        int cnt = 0;
        for (int i = 0; i < nums_.size(); ++i) {
            if (nums_[i] == target) {
                ++cnt;
                int tmp = rand() % cnt;
                if (tmp == 0) res = i;
            }
        }
        return res;
    }

    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
