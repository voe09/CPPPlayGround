/*
Given a non-empty string containing an out-of-order English representation of 
digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. 
That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> lookup;
        for (const auto &c: s) {
            ++lookup[c];
        }
        vector<int> nums(10, 0);
        nums[0] = lookup['z'];
        nums[2] = lookup['w'];
        nums[4] = lookup['u'];
        nums[6] = lookup['x'];
        nums[8] = lookup['g'];
        nums[1] = lookup['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = lookup['h'] - nums[8];
        nums[5] = lookup['f'] - nums[4];
        nums[7] = lookup['s'] - nums[6];
        nums[9] = lookup['i'] - nums[6] - nums[8] - nums[5];
        string res;
        for (int i = 0; i < 10; ++i) {
            char tmp = '0' + i;
            for (int j = 0; j < nums[i]; ++j) {
                res += tmp;
            }
        }
        return res;
    }
};
