/*
Given an array nums containing n + 1 integers where each integer is between 1 
and n (inclusive), prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (const auto &num: nums) {
                if (num <= mid) ++cnt;
            }
            if (cnt <= mid) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};



// Wront answer: modify the array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        return insertionSort(nums);
    }

private:
    int insertionSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int key = nums[i];
            int j = i - 1;

            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                --j;
            }
            if (nums[j] == key) return key;
            nums[j + 1] = key;
        }
    }
};

// best solution
http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/


