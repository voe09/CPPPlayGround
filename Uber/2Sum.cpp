/*
Given an array of integers, return indices of the two numbers such that they 
add up to a specific target.

You may assume that each input would have exactly one solution, and you may 
not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

vector<int> TwoSum(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        if (nums[left] + nums[right] > target) --right;
        else if (nums[left] + nums[right] < target) ++left;
        else {
            break;
        }
    }
    return {nums[left], nums[right]};
}
