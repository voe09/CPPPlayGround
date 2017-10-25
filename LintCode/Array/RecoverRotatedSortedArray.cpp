/*
Given a rotated sorted array, recover it to sorted array in-place.

Clarification
What is rotated array?

For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
Example
[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

Challenge
In-place, O(1) extra space and O(n) time.
 */

/*
首先可以想到逐步移位，但是这种方法显然太浪费时间，不可取。下面介绍利器『三步翻转法』，以[4, 5, 1, 2, 3]为例。

首先找到分割点5和1
翻转前半部分4, 5为5, 4，后半部分1, 2, 3翻转为3, 2, 1。整个数组目前变为[5, 4, 3, 2, 1]
最后整体翻转即可得[1, 2, 3, 4, 5]
由以上3个步骤可知其核心为『翻转』的in-place实现。使用两个指针，一个指头，一个指尾，使用for循环移位交换即可。
 */

class Solution {
public:
    /*
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        return recoverRotatedSortedArray(nums, 0);
    }

private:
    void recoverRotatedSortedArray(vector<int> &nums, int start) {
        if (start >= nums.size() - 1) return;
        int idx = start + 1;
        for (; idx < nums.size(); ++idx) {
            if (nums[idx] < nums[idx - 1]) break;
        }
        
        if (idx == nums.size()) return;

        for (int i = idx; i < nums.size(); ++i) {
            swap(nums[i], nums[i - idx + start]);
        }

        return recoverRotatedSortedArray(nums, start + nums.size() - idx);
    }
};


class Solution {
public:
    /*
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int left = 0, right = 1;
        for (; right < nums.size(); ++left, ++right) {
            if (nums[right] < nums[left]) break;
        }
        if (right == nums.size()) return;
        rotateArray(nums, 0, left);
        rotateArray(nums, right, nums.size() - 1);
        rotateArray(nums, 0, nums.size() - 1);
    }

private:
    void rotateArray(vector<int> &nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};
