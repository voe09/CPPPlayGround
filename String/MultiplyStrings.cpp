/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()) return "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ret(num1.size()+num2.size(),'0');
        
        for(int j=0; j<num2.size(); j++) {
            int carry = 0;
            int val = num2[j] - '0';
            for(int i=0; i<num1.size(); i++) {
                carry += ((num1[i]-'0')*val + (ret[i+j]-'0'));
                ret[i+j] = carry%10 + '0';
                carry /= 10;
            }
            if(carry!=0) ret[num1.size()+j] = carry + '0';
        }
        reverse(ret.begin(),ret.end());
        
        int count = 0;
        while(count<ret.size()-1 && ret[count]=='0') count++;
        ret.erase(0,count);
        return ret;
    }
};
