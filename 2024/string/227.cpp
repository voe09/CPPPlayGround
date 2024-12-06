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