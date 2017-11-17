/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:

pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
 

Notes:
You may assume both pattern and str contains only lowercase letters.
*/
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

bool helper(string &pattern, int p, string &str, int s, unordered_set<string> &visited, unordered_map<char, string> &m) {
    if (p == pattern.size() && s == str.size()) return true;
    if (p == pattern.size() || s == str.size()) return false;

    char c = pattern[p];
    for (int i = s; i < str.size(); ++i) {
        string tmp = str.substr(s, i - s + 1);
        if (m.count(c) && m[c] == tmp) {
            if (helper(pattern, p + 1, str, i + 1, visited, m)) return true;
        }
        else if (!m.count(c)) {
            if (visited.count(tmp)) continue;
            m[c] = tmp;
            visited.insert(tmp);
            if (helper(pattern, p + 1, str, i + 1, visited, m)) return true;
            m.erase(c);
            visited.erase(tmp);
        }
    }
    return false;
}

bool isPattern(string pattern, string str) {
    unordered_map<char, string> m;
    unordered_set<string> visited;
    return helper(pattern, 0, str, 0, visited, m);
}

int main() {
    std::cout << isPattern("abab", "redblueredblue") << std::endl;
}
