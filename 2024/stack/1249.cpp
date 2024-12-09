class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> stk;
        int cnt = 0;
        for (char c : s) {
            if (c != '(' && c != ')') stk.push(c);
            else if (c == '(') {
                cnt++;
                stk.push(c);
            } else if (c == ')' && cnt <= 0) {
                continue;
            } else {
                cnt--;
                stk.push(c);
            }
        }

        string res;
        while (!stk.empty()) {
            char c = stk.top();
            stk.pop();
            if (c != '(' && c != ')') res.push_back(c);
            else if (c == ')') {
                cnt--;
                res.push_back(c);
            } else if (c == '(' && cnt > 0) {
                cnt--;
                continue;
            } else {
                cnt++;
                res.push_back(c);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};