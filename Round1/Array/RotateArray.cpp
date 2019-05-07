/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
*/

// https://leetcode.com/problems/rotate-array/#/solutions

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int start = 1;
        int num_rotate = 0;
        int n = nums.size();
        k %= n;
        if ((n == 0) || (k <= 0)) return;
        int current = start;
        while (num_rotate < n) {
            current = start;
            int cached_num = nums[current];
            do {
                int tmp = cached_num;
                cached_num = nums[(current + k) % n];
                nums[(current + k) % n] = tmp;
                current = (current + k) % n;
                num_rotate += 1;
            } while (current != start);
            ++start;
        }
        return;
    }
};


// 另一种做法
// (1) reverse the array;
// (2) reverse the first k elements;
// (3) reverse the last n-k elements.
// The first step moves the first n-k elements to the end, and moves the last k elements to the front. The next two steps put elements
// the right order.

public class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        k %= len;
        reverse(nums, 0, len-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, len-1);
    }

    public void reverse(int[] nums, int l, int r) {
        while (l <= r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }
};
