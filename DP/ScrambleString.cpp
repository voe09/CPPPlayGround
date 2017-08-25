/*
Given a string s1, we may represent it as a binary tree by partitioning it to
two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces
a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it
produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */
/*
就是s1和s2是scramble的话，那么必然存在一个在s1上的长度l1，将s1分成s11和s12两段，
同样有s21和s22.那么要么s11和s21是scramble的并且s12和s22是scramble的；
要么s11和s22是scramble的并且s12和s21是scramble的
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false;
        for (int i = 1; i < s1.size(); ++i) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
            s21 = s2.substr(s1.size() - i);
            s22 = s2.substr(0, s1.size() - i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
        }
        return false;
    }
};

/* DP
三维动态规划的题目，我们提出维护量res[i][j][n]，其中i是s1的起始字符，
j是s2的起始字符，而n是当前的字符串长度，res[i][j][len]表示的是以i和j分别为s1和
s2起点的长度为len的字符串是不是互为scramble。
有了维护量我们接下来看看递推式，也就是怎么根据历史信息来得到res[i][j][len]。
判断这个是不是满足，其实我们首先是把当前s1[i...i+len-1]字符串劈一刀分成两部分，
然后分两种情况：第一种是左边和s2[j...j+len-1]左边部分是不是scramble，
以及右边和s2[j...j+len-1]右边部分是不是scramble；第二种情况是左边和s2[j...j+len-1]
右边部分是不是scramble，以及右边和s2[j...j+len-1]左边部分是不是scramble。
如果以上两种情况有一种成立，说明s1[i...i+len-1]和s2[j...j+len-1]是scramble的。
而对于判断这些左右部分是不是scramble我们是有历史信息的，因为长度小于n的所有情况
我们都在前面求解过了（也就是长度是最外层循环）。
上面说的是劈一刀的情况，对于s1[i...i+len-1]我们有len-1种劈法，在这些劈法中只要
有一种成立，那么两个串就是scramble的。
总结起来递推式是
res[i][j][len] = || (res[i][j][k]&&res[i+k][j+k][len-k] || res[i][j+len-k][k]&&res[i+k][j][len-k])
对于所有1<=k<len，也就是对于所有len-1种劈法的结果求或运算。因为信息都是计算过的，
对于每种劈法只需要常量操作即可完成，因此求解递推式是需要O(len)（因为len-1种劈法）。
如此总时间复杂度因为是三维动态规划，需要三层循环，加上每一步需要线行时间求解递推式，
所以是O(n^4)。虽然已经比较高了，但是至少不是指数量级的，动态规划还是有很大优势的，
空间复杂度是O(n^3)
 */

// DP 
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int n = s1.size();
        vector<vector<vector<bool> > > dp (n, vector<vector<bool> >(n, vector<bool>(n + 1, false)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                for (int j = 0; j <= n - len; ++j) {
                    for (int k = 1; k < len; ++k) {
                        if ((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i + k][j][len - k] && dp[i][j + len - k][k])) {
                            dp[i][j][len] = true;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};

// http://www.cnblogs.com/grandyang/p/4318500.html
