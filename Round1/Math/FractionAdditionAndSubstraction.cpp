/*
Given a string representing an expression of fraction addition and subtraction,
you need to return the calculation result in string format. The final result
should be irreducible fraction. If your final result is an integer, say 2, you
need to change it to the format of fraction that has denominator 1. So in this
case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. 
If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and 
denominator of each fraction will always be in the range [1,10]. If the 
denominator is 1, it means this fraction is actually an integer in a 
fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid 
and in the range of 32-bit int.
 */

/*
只考虑了两个分数相加
 */

class Solution {
public:
    string fractionAddition(string expression) {
        istringstream is(expression);
        int dividend = 0, divisor = 0;
        char op;
        vector<int> dividends;
        vector<int> divisors;
        while (is >> dividend >> op >> divisor) {
            dividends.push_back(dividend);
            divisors.push_back(divisor);
        }
        int A = dividend[0] * divisor[1] + dividend[1] * divisor[0];
        int B = divisor[0] * divisor[1];
        int g = gcd(A, B);
        A /= g;
        B /= g;
        return to_string(A) + "/" + to_string(B);
    }

private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};


class Solution {
public:
    string fractionAddition(string expression) {
        istringstream is(expression);
        int num = 0, dem = 0, A = 0, B = 1;
        char c;
        while (is >> num >> c >> dem) {
            A = A * dem + num * B;
            B *= dem;
            int g = abs(gcd(A, B));
            A /= g;
            B /= g;
        }
        return to_string(A) + "/" + to_string(B);
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
