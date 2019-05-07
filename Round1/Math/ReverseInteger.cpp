/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. 
Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, 
cases such as 10, 100.

Did you notice that the reversed integer might overflow? 
Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. 
How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 
when the reversed integer overflows.

Note:
The input is assumed to be a 32-bit signed integer. Your function 
should return 0 when the reversed integer overflows. 
*/

class Solution {
public:
    int reverse(int x) {
        if (x == 0 || x == INT_MAX || x == INT_MIN) return 0;
        int sign = (x > 0) ? 1 : -1;
        x = abs(x);
        string res = "";
        while (x != 0) {
            int carry = x % 10;
            x /= 10;
            char tmp = '0' + carry;
            res = res + tmp;
        }
        string max = (sign > 0) ? to_string(INT_MAX) : to_string (INT_MIN);
        if (sign < 0)
            max = max.substr(1);

        if (res.size() == max.size()) {
            bool overflow = true;
            for (int i = 0; i < res.size(); ++i) {
                if (res[i] - '0' < max[i] - '0')
                    break;
                else if (res[i] - '0' == max[i] - '0')
                    continue;
                else
                    return 0;
            }

        }
        int zeros = 0;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == '0')
                ++zeros;
            else
                break;
        }
        res = res.substr(zeros);
        return sign * stoi(res);
    }
};

