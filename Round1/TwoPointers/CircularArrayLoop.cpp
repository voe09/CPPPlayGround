/*
You are given an array of positive and negative integers. If a number n at an 
index is positive, then move forward n steps. Conversely, if it's negative (-n), 
move backward n steps. Assume the first element of the array is forward next to 
the last element, and the last element is backward next to the first element. 
Determine if there is a loop in this array. A loop starts and ends at a 
particular index with more than 1 element along the loop. The loop must 
be "forward" or "backward'.

Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 
0 -> 2 -> 3 -> 0.

Example 2: Given the array [-1, 2], there is no loop.

Note: The given array is guaranteed to contain no element "0".

Can you do it in O(n) time complexity and O(1) space complexity?
 */

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if (nums.empty()) return false;
        for (int i = 0; i < nums.size(); ++i) {
            if (circularArrayLoopIndex(nums, i)) return true;
        }
        return false;
    }

private:
    bool circularArrayLoopIndex(vector<int>& nums, int start) {
        int slow = start, fast = start;
        int length = nums.size();
        do {
            slow += nums[slow];
            while (slow < 0) {
                slow += length;
            }
            while (slow >= length) {
                slow -= length;
            }
            fast += nums[fast];
            while (fast < 0)
                fast += length;
            while (fast >= length)
                fast -= length;
            fast += nums[fast];
            while (fast < 0) {
                fast += length;
            }
            while (fast >= length) {
                fast -= length;
            }
        } while (slow != fast);
        slow += nums[slow];
        while (slow < 0) {
            slow += length;
        }
        while (slow >= length) {
            slow -= length;
        }
        if (slow == fast) return false;
        slow = fast;
        int sign = (nums[slow] > 0) ? 1 : -1;
        do {
            slow += nums[slow];
            while (slow < 0) {
                slow += length;
            }
            while (slow >= length) {
                slow -= length;
            }
            if (nums[slow] * sign < 0) return false;
        } while (slow != fast);
        return true;
    }
};
