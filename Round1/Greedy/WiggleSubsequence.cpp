/*
A sequence of numbers is called a wiggle sequence if the differences between 
successive numbers strictly alternate between positive and negative. The first 
difference (if one exists) may be either positive or negative. A sequence with 
fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences 
(6,-3,5,-7,3) are alternately positive and negative. In contrast, 
[1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because 
its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that 
is a wiggle sequence. A subsequence is obtained by deleting some number of 
elements (eventually, also zero) from the original sequence, leaving the 
remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
 */

// DP
// 两个dp数组p和q，其中p[i]表示到i位置时首差值为正的摆动子序列的最大长度
// q[i]表示到i位置时首差值为负的摆动子序列的最大长度
// 我们从i=1开始遍历数组，然后对于每个遍历到的数字，再从开头位置遍历到这个数字，
// 然后比较nums[i]和nums[j]，分别更新对应的位置
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> p(nums.size(), 1);
        vector<int> q(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) p[i] = max(p[i], q[j] + 1);
                else if (nums[i] < nums[j]) q[i] = max(q[i], p[j] + 1);
            }
        }
        return max(p.back(), q.back());
    }
};


// Greedy 这里我们不在维护两个dp数组，而是维护两个变量p和q，然后遍历数组，
// 如果当前数字比前一个数字大，则p=q+1，如果比前一个数字小，则q=p+1，
// 最后取p和q中的较大值跟n比较，取较小的那个

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int p = 1, q = 1, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) p = q + 1;
            else if (nums[i] < nums[i - 1]) q = p + 1;
        }
        return min(n, max(p, q));
    }
};


// 看到这个就想到和LIS差不多，迅速的DP一下，1A，
// 设dp[i] 为以i结尾的最大摆动序列长度，sign[i]为i这个数比之前的大还是小（大为1，小-1，初始0），更新条件如下：
// dp[j] + 1 > dp[i] and (sign[j] > 0 and nums[i] < nums[j] or sign[j] < 0 
// and nums[i] > nums[j] or sign[j] == 0 and nums[i] != nums[j]):

/* LIS 的延伸 
Let A is given array of length n of integers. We define a 2D array Z[n][2] such
that Z[i][0] contains longest Zig-Zag subsequence ending at index i and last 
element is greater than its previous element and Z[i][1] contains longest 
Zig-Zag subsequence ending at index i and last element is smaller than its 
previous element, then we have following recurrence relation between them,

Z[i][0] = Length of the longest Zig-Zag subsequence 
          ending at index i and last element is greater
          than its previous element
Z[i][1] = Length of the longest Zig-Zag subsequence 
          ending at index i and last element is smaller
          than its previous element

Recursive Formulation:
   Z[i][0] = max (Z[i][0], Z[j][1] + 1); 
             for all j < i and A[j] < A[i] 
   Z[i][1] = max (Z[i][1], Z[j][0] + 1); 
             for all j < i and A[j] > A[i]

*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<vector<int>> dp(2, vector<int>(nums.size(), 1));

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[1][i] = max(dp[1][i], dp[0][j] + 1);
                } else if (nums[i] < nums[j]) {
                    dp[0][i] = max(dp[0][i], dp[1][j] + 1);
                }
            }
        }
        return max(dp[0].back(), dp[1].back());
    }
};


// Greedy
/*摇摆序列要求升高，降低，升高。。。
或者降低，升高，降低。。。
那么我们只要找出数组中的“拐点” 即可 举个例子:
4 5 6  3 2 1这几个数中，4为起点，那么5和6中，我们肯定选6啊~因为之后的数要求小于5，小于5的必定也小于6 比如改为4 5 6 5，之前要是选5就没办法继续往下了。。
总之就是选最小的和选最大的（也就是拐点） 保证不丢最优解。
*/

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		int ans = 1;
		for (int i = 1, j = 0; i < n; j = i,i++) {
			if (nums[j] < nums[i]) {
				ans++;
				while (i + 1 < n && nums[i] <= nums[i + 1]) i++;
			}
			else if (nums[j] > nums[i]) {
				ans++;
				while (i + 1 < n && nums[i] >= nums[i + 1]) i++;
			}
		}
		return ans;
	}
};
