/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

/*
 * 题目意思是在现在vector的所有permutations里找到仅仅比现在的排序大的排序
 */


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int permute_num = nums[len - 1];
        int permute_loc = len - 1;
        bool permutationable = false;
        for (int i = len - 2; i >= 0; --i) {
            if (nums[i] < permute_num) {
                permute_num = nums[i];
                permute_loc = i;
                permutationable = true;
                break;
            } else {
                permute_num = nums[i];
                permute_loc = i;
            }
        }
        
        if (!permutationable) {
            std::reverse(num.begin(), nums.end());
            return;
        }

        // binary search in permute_loc + 1 to len - 1, find the one that is 
        // larger than permute_num
        int ben = permute_loc + 1;
        int end = len - 1;
        while (end - ben > 1) {
            int mid = ben + (end - ben) / 2;
            if (nums[mid] > permute_num)
                ben = mid;
            else
                end = mid - 1;
        }
        
        int change_loc;
        if (nums[end] > permute_num || end == 0)
            change_loc = end;
        else
            change_loc = ben;

        std::iter_swap(nums.begin() + permute_loc, nums.begin() + change_loc);
        std::reverse(nums.begin() + permute_loc + 1, nums.end());
    }
};
