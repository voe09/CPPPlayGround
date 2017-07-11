/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        int length = tokens.size();
        stack<int> stk;
        for (int i = 0; i < length; ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                stk.push(stoi(tokens[i]));
            }
            else {
                int tmp2 = stk.top();
                stk.pop();
                int tmp1 = stk.top();
                stk.pop();
                if (tokens[i] == "+") {
                    int sum = tmp1 + tmp2;
                    stk.push(sum);
                } else if (tokens[i] == "-") {
                    int minus = tmp1 - tmp2;
                    stk.push(minus);
                } else if (tokens[i] == "*") {
                    int multiply = tmp1 * tmp2;
                    stk.push(multiply);
                } else {
                    int divide = tmp1 / tmp2;
                    stk.push(divide);
                }
            }
        }
        return stk.top();
    }
};
