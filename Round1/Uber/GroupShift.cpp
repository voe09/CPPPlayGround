/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
 

Note: For the return value, each inner list's elements must follow the lexicographic order.
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<vector<string>> GroupShift(vector<string> str) {
    unordered_map<string, vector<string>> m;
    for (const auto &s : str) {
        string tmp;
        for (const auto &c : s) {
            tmp += (c - s[0] + 26) % 26 + 'a';
        }
        m[tmp].push_back(s);
    }

    vector<vector<string>> res;
    for (const auto &pair : m) {
        res.push_back(pair.second);
    }
    return res;
}

int main() {
    auto res = GroupShift({"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"});
    for (const auto &vec : res) {
        for (const auto &s : vec) {
            cout << s << " ";
        }
        cout << endl;
    }
}
