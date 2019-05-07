/*
A sequence of numbers is called arithmetic if it consists of at least three
elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A subsequence slice 
of that array is any sequence of integers (P0, P1, ..., Pk) such that 
0 ≤ P0 < P1 < ... < Pk < N.

A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the 
sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, 
this means that k ≥ 2.

The function should return the number of arithmetic subsequence slices in 
the array A.

The input contains N integers. Every integer is in the range of -231 and 231-1 
and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.


Example:

Input: [2, 4, 6, 8, 10]

Output: 7

Explanation:
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
 */

// 建立一个一维数组dp，数组里的元素不是数字，而是放一个哈希表，
// 建立等差数列的差值和其长度之间的映射, 我们遍历数组中的所有数字，
// 对于当前遍历到的数字，又从开头遍历到当前数字，计算两个数字之差diff，
// 如果越界了不做任何处理，如果没越界，我们看dp[i]中diff的差值映射自增1，
// 然后我们看dp[j]中是否有diff的映射，如果有的话，说明此时已经能构成等差数列了;
// 将dp[j][d]加入结果res中，然后再更新dp[i][d]，这样等遍历完数组，res即为所求

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = A[i] - A[j];
                ++dp[i][diff];
                if (dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)A[i] - (long long)A[j];
                if (diff > INT_MAX || diff < INT_MIN) continue;
                int d = (int)diff;
                if (!dp[i].count(d)) dp[i][d] = 0;
                ++dp[i][d];
                if (dp[j].count(d)) {
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};
