/*
Given an array of n positive integers and a positive integer s, find the 
minimal length of a subarray of which the sum ≥ s. If there isn't one, 
return -1 instead.

Have you met this question in a real interview? Yes
Example
Given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal 
length under the problem constraint.

Challenge 
If you have figured out the O(n) solution, try coding another solution of which
the time complexity is O(n log n).
 */

/*
需要定义两个指针left和right，分别记录子数组的左右的边界位置，然后我们让right向
右移，直到子数组和大于等于给定值或者right达到数组末尾，此时我们更新最短距离，
并且将left像右移一位，然后再sum中减去移去的值，然后重复上面的步骤，直到right到达
末尾，且left到达临界位置，即要么到达边界，要么再往右移动，和就会小于给定值
 */

class Solution {
public:
    /*
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> nums, int s) {
        // write your code here
        if (nums.empty()) return -1;
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        while (right < len) {
            while (sum < s && right < len) {
                sum += nums[right++];
            }
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }

        return res == len + 1 ? -1 : res;
    }
};

// O(nlogn)
/*
我们建立一个比原数组长一位的sums数组，其中sums[i]表示nums数组中[0, i - 1]的和,
然后我们对于sums中每一个值sums[i]，用二分查找法找到子数组的右边界位置，使该子数
组之和大于sums[i] + s，然后我们更新最短长度的距离即可。
 */
// 因为是n positive integer，所以是sum是递增序列
class Solution {
public:
    /*
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> nums, int s) {
        // write your code here
        int len = nums.size(), sums[len + 1] = {0}, res = len + 1;
        for (int i = 1; i < len + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < len + 1; ++i) {
            int right = searchRight(i + 1, len, sums[i] + s, sums);
            if (right == len + 1) break;
            if (res > right - i) res = right - i;
        }
        return res == len + 1 ? 0 : res;
    }

        int searchRight(int left, int right, int key, int sums[]) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (sums[mid] >= key) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};
