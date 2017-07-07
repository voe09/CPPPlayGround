/*
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

/*
 * idea:
 * DP解法:
 * 这道题求最值，首先想到的是DP。
DP[i]表示以S[i]结尾的（即必须包括S[i]）的longest valid parentheses。
状态函数：
如果S[i] == '('，则以S[i]结尾的序列必然不可能是合法的，因此DP[i]=0。
if s[i] == ')' and s[i - 1] == '(', then dp[i] = dp[i-2] + 2
if s[i] == ')' and s[i - 1] == ')' and s[i - dp[i - 1] -1] == '(' then 
dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]

stack解法:
第二种方法受到valid parentheses的启发，可以用stack来解，只不过栈中保存的是index。
遇到'('无条件入栈
遇到')'则需要和栈中保存的'('配对消除，这时候又分两种情况：
1） 栈空。则之前的valid串到此为止，需要将此时的位置记录为新的开始位置，即用一个start来记录此时的index。+

2）栈不空。如果栈中'('出栈之后栈依然不空，则将栈顶元素的index作为边界，用此时的index减去栈顶元素的index即可求出新长度。如果出栈后栈变为空，则将start记录的位置作为边界，用此时的index减去start即可求出新长度。将新长度与最大长度比较，如果更大则更新最大长度。
 */

// dp
class Solution {
    public:
        int longestValidParentheses(string s) {
            int n = s.size();
            int len = 0;
            vector<int> dp(n, 0);

            for (int i = 1; i < n; ++i) {
                if (s[i] == ')') {
                    if (s[i-1] == '(') {
                        dp[i] = 2;
                        if (i >= 2)
                            dp[i] += dp[i-2];
                    }
                    else {
                        int idx = i - dp[i-1] - 1;
                        if (idx >= 0 && s[idx] == '(') {
                            dp[i] = dp[i-1] + 2;
                            if (idx > 0)
                                dp[i] += dp[idx -1];
                        }
                    }
                }
                len = max(len, dp[i]);
            }
            return len;
        }
};


// Stack
class Solution {
public:
    int longestValidParentheses(string s) {
            
    }
};
