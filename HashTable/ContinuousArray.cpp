/*
Given a binary array, find the maximum length of a contiguous subarray with 
equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
 */

// TLE
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> zeros (n + 1, 0);
        vector<int> ones (n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] == 0) {
                zeros[i] = zeros[i - 1] + 1;
                ones[i] = ones[i - 1];
            } else {
                zeros[i] = zeros[i - 1];
                ones[i] = ones[i - 1] + 1;
            }
        }
        
        int res = 0;
        for (int left = 1; left < n; ++left) {
            for (int right = left + 1; right <= n; ++right) {
                int num_zeros = zeros[right] - zeros[left - 1];
                int num_ones = ones[right] - ones[left - 1];
                if (num_zeros == num_ones) res = max(res, right - left + 1);
            }
        }
        return res;
    }
};



/*求累积和是一种很犀利的工具，但是这里怎么将子数组的和跟0和1的个数之间产生联系呢？
我们需要用到一个trick，遇到1就加1，遇到0，就减1，这样如果某个子数组和为0，
就说明0和1的个数相等，这个想法真是太叼了，不过博主木有想出来。知道了这一点，
我们用一个哈希表建立子数组之和跟结尾位置的坐标之间的映射
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (m.count(sum)) {
                res = max(res, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return res;
    }
};


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = 0, n = nums.size(), res = 0;
        unordered_map<int, int> sums {{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (sums.count(sum)) {
                res = max(res, i - sums[sum]);
            } else {
                sums[sum] = i;
            }
        }
        return res;
    }
};
