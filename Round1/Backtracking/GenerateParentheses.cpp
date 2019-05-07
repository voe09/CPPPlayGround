/*
Given n pairs of parentheses, write a function to generate all combinations of 
well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS(n, n, "", res);
        return res;
    }

private:
    bool isValid(const string& parentheses) {
        int stk = 0;
        for (const auto& c : parentheses) {
            if (c == '(') stk += 1;
            if (c == ')') {
                if (stk > 0) stk -= 1;
                else return false;
            }
        }
        if (stk == 0) return true;
        else return false;
    }

    void DFS(int left, int right, string cur, vector<string>& res) {
        if (left == 0 && right == 0) {
            if (isValid(cur)) res.push_back(cur);
            return;
        }

        if (left > 0) {
            DFS(left - 1, right, cur + '(', res);
        }
        if (right > 0) {
            DFS(left, right - 1, cur + ')', res);
        }
    }
};
