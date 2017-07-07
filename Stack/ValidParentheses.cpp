/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (auto& character: s) {
            if (character == '(' || character == '{'
                || character == '[') 
                stack.push(character);
            else if (character == ')' || character == '}'
                    || character == ']') {
                char tmp;
                if (!stack.empty())
                    tmp = stack.top();
                else return false;
                if (character == ')') {
                    if (tmp != '(') return false;
                } else if (character == '}') {
                    if (tmp != '{') return false;
                } else {
                    if (tmp != '[') return false;
                }
                stack.pop();
            }
        }
        if (stack.empty())
            return true;
        else return false;
    }
};
