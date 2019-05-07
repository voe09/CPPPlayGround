/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces and the words are always separated by a single space.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Could you do it in-place without allocating extra space?
*/
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string reverseString(string str) {
    if (str.empty()) return str;
    reverse(str.begin(), str.end());
    int i = 0, j = 0;
    while (j < str.size()) {
        while (j < str.size() && str[j] != ' ') ++j;
        reverse(str.begin() + i, str.begin() + j);
        ++j;
        i = j;
    }
    return str;
}

int main() {
    std::cout << reverseString("the sky is blue") << std::endl;
}
