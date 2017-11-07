/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

Have you met this question in a real interview? Yes
Example
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

class Solution {
public:
    /*
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code here
        int n = s.size();
        if (n == 0) return true;
        else if (n % 2 != 0) return false;
        stack<char> stk;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            }
            else {
                if (stk.empty()) return false;
                if (s[i] == ')') {
                    if (stk.top() != '(') return false;
                    stk.pop();
                }
                else if (s[i] == '}') {
                    if (stk.top() != '{') return false;
                    stk.pop();
                }
                else {
                    if (stk.top() != '[') return false;
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};
