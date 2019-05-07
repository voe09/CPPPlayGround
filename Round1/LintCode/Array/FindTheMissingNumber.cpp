/*
 Given an array contains N numbers of 0 .. N, find which number doesn't exist
 in the array.

Have you met this question in a real interview? Yes
Example
Given N = 3 and the array [0, 1, 3], return 2.

Challenge 
Do it in-place with O(1) extra memory and O(n) time.
 */

class Solution {
public:
    /*
     * @param nums: An array of integers
     * @return: An integer
     */
    int findMissing(vector<int> nums) {
        // write your code here
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            while (nums[i] != i && nums[i] != N) {
                int swap_idx = nums[i];
                swap(nums[swap_idx], nums[i]);
            }
        }

        for (int i = 0; i < N; ++i) {
            if (nums[i] == N) return i;
        }

        return N;
    }
};
