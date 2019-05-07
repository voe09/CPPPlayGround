/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown 
to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return true;
            else {
                if (nums[mid] < nums[end]) { // right half sorted
                    if (nums[mid] < target && target <= nums[end])
                        start = mid + 1;
                    else
                        end = mid - 1;
                } else if (nums[mid] > nums[end]) { // left half sorted
                    if (nums[mid] > target && target >= nums[start])
                        end = mid - 1;
                    else
                        start = mid + 1;
                } else {
                    --end;
                }
            }
        }
        return false;
    }
};
