Given a list of words, find whether a new word is anagram of word in list

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


bool isAnagram(vector<string> &words, string s) {
    if (words.empty()) return false;
    unordered_set<string> dict;
    for (const auto &word : words) {
        vector<int> char_cnts (52, 0);
        for (const auto &c : word) {
            int idx = (c >= 'a' && c <= 'z' ) ? c - 'a' : c - 'A' + 26;
            ++char_cnts[idx];
        }
        string tmp = "";
        for (int i = 0; i < 26; ++i) {
            tmp += to_string(char_cnts[i]);
        }
        dict.insert(tmp);
    }
    
    vector<int> counts (26, 0);
    for (const auto &c : s) {
        int idx = (c >= 'a' && c <= 'z') ? c - 'a' : c - 'A' + 26;
        ++counts[idx];
    }
    string res = "";
    for (int i = 0; i < 26; ++i) {
        res += to_string(counts[i]);
    }
    return dict.count(res);
}

int main() {
    vector<string> words {"Uber", "UberRide", "Haoyang"};
    std::cout << isAnagram(words, "bUer") << std::endl;
    std::cout << isAnagram(words, "yangHao") << std::endl;
    std::cout << isAnagram(words, "Ride") << std::endl;
}
