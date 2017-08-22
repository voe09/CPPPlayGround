/*
Remove the minimum number of invalid parentheses in order to make the input string valid. 
Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
 */

/*
Limit max removal rmL and rmR for backtracking boundary. Otherwise it will 
exhaust all possible valid substrings, not shortest ones. Scan from left to 
right, avoiding invalid strs (on the fly) by checking num of open parens.
If it's '(', either use it, or remove it.
If it's '(', either use it, or remove it.
Otherwise just append it.
Lastly set StringBuilder to the last decision point.
In each step, make sure:
i does not exceed s.length().
Max removal rmL rmR and num of open parens are non negative.
De-duplicate by adding to a HashSet.
 */

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
    int left_removed = 0, right_removed = 0;
    findMinRemove(s, left_removed, right_removed);

    vector<string> res;
    removeInvalidParenthesesHelper(s, 0, left_removed, right_removed, res);
    return res;
    }

private:
    void findMinRemove(const string& s, int& left_removed, int& right_removed) {
        for (const auto& c : s) {
            if (c == '(') {
                ++left_removed;
            } else if (c == ')') {
                if (!(left_removed))
                    ++right_removed;
                else
                    --left_removed;
            }
        }
    }

    void removeInvalidParenthesesHelper(const string& s, int start, int left_removed, int right_removed, vector<string>& res) {
        if (!left_removed && !right_removed) {
            if (isValid(s))
                res.push_back(s);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (right_removed == 0 && left_removed > 0 && s[i] == '(') {
                if (i == start || s[i] != s[i - 1]) { // skip duplicated
                    string tmp = s;
                    tmp.erase(i , 1);
                    removeInvalidParenthesesHelper(tmp, i, left_removed - 1, right_removed, res);
                }
            } else if (right_removed > 0 && s[i] == ')') {
                if (i == start || s[i] != s[i - 1]) {
                    string tmp = s;
                    tmp.erase(i, 1);
                    removeInvalidParenthesesHelper(tmp, i, left_removed, right_removed - 1, res);
                }
            }
        }
    }

    bool isValid(const string& s) {
        int sum = 0;
        for (const auto& c : s) {
            if (c == '(') {
                ++sum;
            } else if (c == ')') {
                --sum;
            }
            if (sum < 0) return false;
        }
        return sum == 0;
    }
};

// BFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, int> visited;
        queue<string> q;
        q.push(s);
        ++visited[s];
        bool found = false;
        while (!q.empty()) {
            s = q.front(); q.pop();
            if (isValid(s)) {
                res.push_back(s);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != '(' && s[i] != ')') continue;
                string t = s.substr(0, i) + s.substr(i + 1);
                if (visited.find(t) == visited.end()) {
                    q.push(t);
                    ++visited[t];
                }
            }
        }
        return res;
    }
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            if (t[i] == ')' && cnt-- == 0) return false;
        }
        return cnt == 0;
    }
};
