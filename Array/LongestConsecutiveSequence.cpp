/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
 */

// Idea: 这道题要求求最长连续序列，并给定了O(n)复杂度限制，我们的思路是，
// 使用一个集合set存入所有的数字，然后遍历数组中的每个数字，如果其在集合中存在，
// 那么将其移除，然后分别用两个变量pre和next算出其前一个数跟后一个数，
// 然后在集合中循环查找，如果pre在集合中，那么将pre移除集合，然后pre再自减1，
// 直至pre不在集合之中，对next采用同样的方法，那么next-pre-1就是当前数字的最长连续序列，
// 更新res即可。代码如下：
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int val : nums) {
            if (!s.count(val)) continue;
            s.erase(val);
            int pre = val - 1, next = val + 1;
            while (s.count(pre)) s.erase(pre--);
            while (s.count(next)) s.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};

// 或者用hash table
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int d : nums) {
            if (!m.count(d)) {
                int left = m.count(d - 1) ? m[d - 1] : 0;
                int right = m.count(d + 1) ? m[d + 1] : 0;
                int sum = left + right + 1;
                m[d] = sum;
                res = max(res, sum);
                m[d - left] = sum;
                m[d + right] = sum;
            }
        }
        return res;
    }
};
