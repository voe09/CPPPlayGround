/*
Given an unsorted array nums, reorder it such that

nums[0] < nums[1] > nums[2] < nums[3]....
 Notice

You may assume all input has valid answer.

Have you met this question in a real interview? Yes
Example
Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].

Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
 */

/*
调整的方法是找到数组的中间的数，相当于把有序数组从中间分成两部分
然后从前半段的末尾取一个，在从后半的末尾去一个，这样保证了第一个数
小于第二个数，然后从前半段取倒数第二个，从后半段取倒数第二个
这保证了第二个数大于第三个数，且第三个数小于第四个数，以此类推直至都取完
 */

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        vector<int> tmp (nums);
        sort(tmp.begin(), tmp.end());
        int left = nums.size() / 2, right = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = i % 2 == 0 ? tmp[right--] : tmp[left--];
        }
    }
};

// O(n) space
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }
    }
};
