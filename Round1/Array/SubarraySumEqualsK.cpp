/*
Given an array of integers and an integer k, you need to find the total number
of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer
k is [-1e7, 1e7].
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        if (nums.empty()) return res;
        int n = nums.size();
        int first = 0, second = 0;
        int sum = nums[0];
        while (first <= second && second < n) {
            if (first == second && sum > k) {
                ++first, ++second;
                sum = nums[first];
            } else if (sum > k) {
                sum -= nums[first];
                ++first;
            } else if (sum < k) {
                ++second;
                sum += nums[second];
            } else {
                ++res;
                sum -= nums[first];
                ++first;
            }
        }
        return res;
    }
};

/*
求和为k的连续子数组的个数，博主最开始看到这道题想着肯定要建立累加和数组
然后遍历累加和数组的每个数字，首先看其是否为k，是的话结果res自增1，然后再加个往前的循环，这样可以快速求出所有的子数组之和，看是否为k
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int i = 0; i < n; ++i) {
            if (sums[i] == k) ++res;
            for (int j = i - 1; j >= 0; --j) {
                if (sums[i] - sums[j] == k) ++res;
            }
        }
        return res;
    }
};


/*
用一个哈希表来建立连续子数组之和跟其出现次数之间的映射，初始化要加入{0,1}这对
映射，这是为啥呢，因为我们的解题思路是遍历数组中的数字，用sum来记录到当前位置的
累加和，我们建立哈希表的目的是为了让我们可以快速的查找sum-k是否存在，即是否有
连续子数组的和为sum-k，如果存在的话，那么和为k的子数组一定也存在，这样当sum
刚好为k的时候，那么数组从起始到当前位置的这段子数组的和就是k，满足题意，如果
哈希表中实现没有m[0]项的话，这个符合题意的结果就无法累加到结果res中，这就是初始化的用途
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> m{{0, 1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            res += m[sum - k];
            ++m[sum];
        }
        return res;
    }
};
