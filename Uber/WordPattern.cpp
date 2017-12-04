/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

bool WordPattern(string pattern, string str) {
    if (pattern.empty() && str.empty()) return true;
    if (pattern.empty() || str.empty()) return false;
    istringstream is(str);
    string word;
    unordered_map<char, string> m;
    int curr = 0;
    while (is >> word) {
        if (m.count(pattern[curr])) {
            if (m[pattern[curr]] != word) return false;
        } else {
            m[pattern[curr]] = word;
        }
        ++curr;
    }
    if (curr != pattern.size()) return false;
    return true;
}

int main() {
    cout << WordPattern("abba", "dog cat cat dog") << endl;
    cout << WordPattern("abba", "dog cat dog dog") << endl;
    cout << WordPattern("abbaa", "dog cat dog dog") << endl;
}
