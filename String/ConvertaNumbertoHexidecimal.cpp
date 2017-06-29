/*
Given an integer, write an algorithm to convert it to hexadecimal. 
For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. 
If the number is zero, it is represented by a single zero character '0'; 
otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library 
which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
*/

// error to transfer negative integers
class Solution {
public:
    string toHex(int num) {
        if (num < 0) num = UINT_MAX + num + 1;
        else if (num == 0) return "0";
        vector<char> map{'a', 'b', 'c', 'd', 'e', 'f'};
        string res;
        while (num > 0) {
            int val = num % 16;
            if (val < 10) res = res + to_string(val);
            else res = res + map[val - 10];
            num /= 16;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    string toHex(int num) {
        if (!num) {
            return "0";
        }

        string result;
        while (num && result.length() != sizeof(int) * 2) {
            int hex = num & 15;
            if (hex < 10) {
                result.push_back('0' + hex);
            } else {
                result.push_back('a' + hex - 10);
            }
            num >>= 4;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
