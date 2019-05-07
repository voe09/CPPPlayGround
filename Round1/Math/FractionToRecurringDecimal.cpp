/*
Given two integers representing the numerator and denominator of a fraction,
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

/* 由于还存在正负情况，处理方式是按正数处理，符号最后在判断，那么我们需要把除数和被除数取绝对值，
那么问题就来了：由于整型数INT的取值范围是-2147483648～2147483647，而对-2147483648取绝对值就会超出范围，
所以我们需要先转为long long型再取绝对值。那么怎么样找循环呢，肯定是再得到一个数字后要看看之前有没有出现这个数。
为了节省搜索时间，我们采用哈希表来存数每个小数位上的数字。还有一个小技巧，由于我们要算出小数每一位，
采取的方法是每次把余数乘10，再除以除数，得到的商即为小数的下一位数字。等到新算出来的数字在之前出现过，
则在循环开始出加左括号，结束处加右括号。代码如下：
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        long long num = abs( (long long)numerator );
        long long den = abs( (long long)denominator );
        long long out = num / den;
        long long rem = num % den;
        unordered_map<long long, int> m;
        string res = to_string(out);
        if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
        if (rem == 0) return res;
        res += ".";
        string s = "";
        int pos = 0;
        while (rem != 0) {
            if (m.find(rem) != m.end()) {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            ++pos;
        }
        return res + s;
    }
};
