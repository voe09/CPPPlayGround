/*
Given a string, print all palindrome permutation
 */

bool isPalindromePerm(unordered_map<char, int> &m) {
    int cnt = 0;
    for (const auto &pair : m) {
        if (pair.second % 2 != 0) ++cnt;
    }
    return cnt <= 1;
}

void helper(string &half, int level, vector<bool> &visited,
            string &tmp, vector<string> &res) {
    
}

vector<string> PalindromePermutation(string s) {
    unordered_map<char, int> m;
    for (const auto &c : s) {
        ++m[c];
    }
    if (!isPalindromePerm(m)) return {};
    vector<string> res;
    string oddChar = "";
    string half = "";
    for (const auto &pair : m) {
        half += to_string(pair.second / 2, pair.first);
        if (pair.second % 2 != 0) {
            oddChar += pair.first;
            break;
        }
    }
    
    int n = half.size();
    vector<bool> visited(n, false);
    string tmp;
    helper(half, 0, visited, tmp, res);
    for (auto &perm : res) {
        perm += oddChar + reverse(perm.begin(), perm.end());
    }
    return res;
}
