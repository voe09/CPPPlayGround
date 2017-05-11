/*
 * Given a sorted array, remove the duplicates in place such that 
 * each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example,
 * Given input array nums = [1,1,2],
 * Your function should return length = 2,
 * with the first two elements of nums being 1 and 2 respectively. 
 * It doesn't matter what you leave beyond the new length.
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int j = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[j]) {
                ++j;
                nums[j] = nums[i];
            }
        }
        nums.resize(j + 1);
        return j + 1;
    }
};

/*
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int j = 0;
        int duplicate = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
                duplicate = 0;
            } else if (nums[i] == nums[j] && duplicate < 1) {
                nums[++j] = nums[i];
                ++duplicate;
            } else {
                ++duplicate;
            }
        }

        return j + 1;
    }
};
