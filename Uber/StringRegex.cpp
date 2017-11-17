// 给出一个string，如果里面有\b就回退一个字符，然后输出最后的结果。比如abb\bc ==> abc
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string StringToString(string input) {
    if (input.empty()) return "";
    stack<char> stk;
    int idx = 0;
    while (idx < input.size()) {
        while (idx < input.size() && input[idx] != '\b') {
            stk.push(input[idx++]);
        }
        
        if (idx != input.size()) {
            stk.pop();
            ++idx;
        }
    }
    
    string res;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string input = "abb\bc";
    std::cout << StringToString(input) << std::endl;
}
