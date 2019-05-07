/*
Implement function atoi to convert a string to an integer.

If no valid conversion could be performed, a zero value is returned.

If the correct value is out of the range of representable values,
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

Have you met this question in a real interview? Yes
Example
"10" => 10
"-1" => -1
"123123123123123" => 2147483647
"1.0" => 1
 */

class Solution {
public:
    /*
     * @param str: A string
     * @return: An integer
     */
    int atoi(string &str) {
        // write your code here
        if (str.empty()) return 0;
        int n = str.size();
        bool neg = false;
        int start = 0;
        if (str[start] == '-') {
            neg = true;
            ++start;
        }
        int res = 0;
        for (int i = start; i < n; ++i) {
            if (!(str[i] >= '0' && str[i] <= '9')) return 0;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            res *= 10;
            res += str[i] - '0'; 
        }

        if (neg)
            return (-1) * res;
        else
            return res;
    }
};


class Solution {
public:
    /*
     * @param str: A string
     * @return: An integer
     */
    int atoi(string &str) {
        // write your code here
        if (str.empty()) return 0;

        int idx = 0;
        while (idx < str.size()) {
            if (str[idx] != ' ')
                break;
            else
                ++idx;
        }

        bool neg = false;
        if (str[idx] == '+') {
            ++idx;
        } else if (str[idx] == '-') {
            ++idx;
            neg = true;
        }

        int res = 0;
        while (idx < str.size() && str[idx] >= '0' && str[idx] <= '9') {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[idx] - '0' > 7)) {
                return (!neg) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + (str[idx++] - '0');
        }

        if (neg) return (-1) * res;
        else return res;
    }
};
