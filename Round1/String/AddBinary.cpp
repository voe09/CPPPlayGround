/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        if (m == 0) return b;
        if (n == 0) return a;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        string res(max(m, n) + 1, '0');
        int carry = 0;
        for (int i = 0; i < min(m, n); ++i) {
            int val = (a[i] - '0') + (b[i] - '0') + carry;
            carry = val / 2;
            res[i] = val % 2 + '0';
        }
        
        string tmp = m < n ? b : a;
        for (int i = min(m, n); i < max(m, n); ++i) {
            int val = (tmp[i] - '0') + carry;
            carry = val / 2;
            res[i] = val % 2 + '0';
        }

        if (carry != 0) res[max(m, n)] = carry + '0';
        std::reverse(res.begin(), res.end());
        if (res[0] == '0') res.erase(0, 1);
        return res;
    }
};
