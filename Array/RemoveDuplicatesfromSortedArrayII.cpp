/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int duplicate = 0;
        int current_idx = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[current_idx] = nums[i];
                current_idx += 1;
                duplicate = 0;
            } else if (duplicate < 1) {
                nums[current_idx] = nums[i];
                current_idx += 1;
                duplicate += 1;
            } else {
                continue;
            }
        }
        return current_idx;
    }
};
