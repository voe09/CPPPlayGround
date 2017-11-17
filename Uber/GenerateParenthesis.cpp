/*
Generate all possible matched parenthesis, given n left parenthesis
and right parenthesis needs to be matched.
*/
#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

bool isValid(string &s) {
    stack<char> stk;
    for (const auto &c : s) {
        if (c == '(') stk.push(c);
        else {
            if (!stk.empty()) stk.pop();
            else return false;
        }
    }
    return (stk.empty());
}

void helper(vector<char> &parenthesis, vector<bool> &visited,
            int idx, string &curr, vector<string> &res) {
    if (idx == visited.size()) {
        if (isValid(curr)) {
            res.push_back(curr);
        }
        return;
    }
    
    for (int i = 0; i < parenthesis.size(); ++i) {
        if (!visited[i]) {
            curr += parenthesis[i];
            visited[i] = true;
            helper(parenthesis, visited, idx + 1, curr, res);
            visited[i] = false;
            curr.pop_back();
        }
    }
}

vector<string> GenerateParenthesis(int n) {
    if (n == 0) return {};
    vector<char> parenthesis;
    for (int i = 0; i < n; ++i) {
        parenthesis.push_back('(');
    }
    for (int i = 0; i < n; ++i) {
        parenthesis.push_back(')');
    }
    vector<bool> visited (2 * n, false);
    vector<string> res;
    string curr;
    helper(parenthesis, visited, 0, curr, res);
    return res;
}

int main() {
    vector<string> res = GenerateParenthesis(3);
    for (const auto &s : res) {
        std::cout << s << std::endl;
    }
}



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};
