#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

void helper(vector<vector<char>> &dict, const string &num,
            int k, vector<int> &curr, unordered_map<string, int> &m) {
    if (k == num.size()) {
        string tmp = "";
        for (int i = 0; i < 26; ++i)
            tmp += to_string(curr[i]);
        if (m.count(tmp)) ++m[tmp];
        return;
    }
    
    auto list = dict[num[k] - '0'];
    for (const auto &c : list) {
        ++curr[c - 'a'];
        helper(dict, num, k + 1, curr, m);
        --curr[c - 'a'];
    }
}

string MostFreqWord(vector<string> &words, vector<string> &nums) {
    unordered_map<string, int> m;
    unordered_map<string, string> lookup;
    for (const auto &word : words) {
        vector<int> counts (26, 0);
        for (const auto &c : word) {
            ++counts[c - 'a'];
        }
        
        string tmp = "";
        for (int i = 0; i < 26; ++i) {
            tmp += to_string(counts[i]);
        }
        
        m[tmp] = 0;
        lookup[tmp] = word;
    }
    
    vector<vector<char>> dict {{}, {'a', 'b', 'c'}, {'d', 'e', 'f'},
                               {'g', 'h', 'i'}, {'j', 'k', 'l'},
                               {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                               {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}, {}};
    vector<int> curr (26, 0);
    for (const auto &num :nums) {
        helper(dict, num, 0, curr, m);
    }
    
    int maxVal = 0;
    string res;
    for (const auto &pair : m) {
        if (pair.second > maxVal) {
            res = pair.first;
            maxVal = pair.second;
        }
    }
    
    return lookup[res];
}

int main() {
    vector<string> words {"uber", "haoyang", "chen"};
    vector<string> nums {"7126", "1762", "6172", "2167"};
    std::cout << MostFreqWord(words, nums) << std::endl;
}
