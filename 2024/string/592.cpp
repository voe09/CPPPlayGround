class Solution {
public:
    string fractionAddition(string expression) {
        if (expression[0] != '-') expression = "+" + expression;

        vector<int> sign;
        vector<int> num;
        vector<int> deno;
        for (int i = 0; i < expression.size();) {
            if (expression[i] == '-') sign.push_back(-1);
            else sign.push_back(1);
            i++;
            int n = 0;
            while (i < expression.size() && expression[i] != '/') {
                n = n * 10 + (expression[i] - '0');
                i++;
            }
            num.push_back(n);
            i++;
            int d = 0;
            while (i < expression.size() && (expression[i] != '+' && expression[i] != '-')) {
                d = d * 10 + (expression[i] - '0');
                i++;
            }
            deno.push_back(d);
        }

        int numerator = 0, denominator = 1;
        for (int i = 0; i < sign.size(); i++) {
            numerator = numerator * deno[i] + sign[i] * num[i] * denominator;
            denominator *= deno[i]; 
        }

        int resign = numerator < 0 ? -1 : 1;

        int g = gcd(numerator * resign, denominator);

        return (resign == -1 ? "-" : "") + to_string(numerator * resign / g) + "/" + to_string(denominator / g);
    }


    int gcd(int a, int b) {
        if (a > b) {
            return gcd(b, a);
        }

        if (a == 0) return b;
        return gcd(b % a, a);
    }
};