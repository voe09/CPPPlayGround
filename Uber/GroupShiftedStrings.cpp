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

#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<string>> GroupShiftedString(vector<string> &strs) {
    sort(strs.begin(), strs.end());
    unordered_map<string, vector<string>> m;

    for (const auto &str : strs) {
        string tmp;
        for (const auto &c : str) {
            tmp += to_string((c - str[0] + 26) % 26) + ",";
        }
        m[tmp].push_back(str);
    }

    vector<vector<string>> res;
    for (const auto &pair : m) {
        res.push_back(pair.second);
    }
    return res;
}

int main() {
    vector<string> strings {"abc", "def", "xyz", "zx", "yw", "a", "z"};
    auto res = GroupShiftedString(strings);
    for (const auto &lists : res) {
        for (const auto &word : lists) {
            std::cout << word << ",";
        }
        std::cout << std::endl;
    }
}
