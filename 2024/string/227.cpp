class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        char op = '+';
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i != s.size() - 1 && s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') num = num * 10 + (s[i] - '0');

            if (s[i] < '0' || s[i] > '9' || i == s.size() - 1) {
                if (op == '+') {
                    nums.push(num);
                } else if (op == '-') {
                    nums.push(-num);
                } else if (op == '*') {
                    int t = nums.top() * num;
                    nums.pop();
                    nums.push(t);
                } else {
                    int t = nums.top() / num;
                    nums.pop();
                    nums.push(t);
                }

                num = 0;
                op = s[i];
            }
        }

        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }

        return res;
    }
};

// repractice
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> stk;
        int num = 0;
        char op = '+';
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (i != n-1 && c == ' ') continue;
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            }
            
            if (c < '0' || c > '9' || i == n-1) {
                if (op == '+') stk.push(num);
                else if (op == '-') stk.push(-num);
                else if (op == '*') {
                    int t = stk.top();
                    stk.pop();
                    stk.push(num * t);
                } else if (op == '/') {
                    int t = stk.top();
                    stk.pop();
                    stk.push(t / num);
                }

                num = 0;
                if (i != n-1) op = c;
            }
        }

        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        return res;
    }
};