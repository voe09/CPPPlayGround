/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. 
Except for the first two numbers, each subsequent number in 
the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, 
so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine 
if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
*/


class Solution {
private:
    bool check(const string& s, int pos, int len1, int len2)
    {
        int start = pos+len1+len2;
        if(start == s.length()) { if(pos==0) return false; return true; }
        int minLen = max(len1, len2);
        if((s[pos]=='0'&&len1>1) || (s[pos+len1]=='0'&&len2>1)) return false;
        long num1 = atol(s.substr(pos, len1).c_str()), num2 = atol(s.substr(pos+len1, len2).c_str());
        if(num1>INT_MAX || num2>INT_MAX) return false;
        for(int l = minLen; l <= (int)s.length()-start; ++l)
        {
            if(l>1 && s[start]=='0') return false;
            long num3 = atol(s.substr(start, l).c_str());
            if(num3 > num1+num2) return false;
            if(num3==num1+num2 && check(s, pos+len1, len2, l)) return true; 
        }
        return false;
    }
public:
    bool isAdditiveNumber(string s) 
    {
        int len = s.length();
        for(int l1 = 1; l1 <= len/2; ++l1)
            for(int l2 = 1; l2 < len-max(l1, l2); ++l2)
                if(check(s, 0, l1, l2)) return true;
        return false;
    }
};
