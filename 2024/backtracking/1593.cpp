class Solution {
public:
    int maxUniqueSplit(string s) {
        int res = 0;
        unordered_map<string, int> st;
        string curr = "";
        helper(s, 0, curr, st, res);
        return res;
    }

private:
    void helper(string& s, int i, string& curr, unordered_map<string, int>& st, int& res) {
        if (i >= s.size()) {
            res = max(res, int(st.size()));
            return;
        }

        curr.push_back(s[i]);

        string prev = curr;
        st[prev]++;
        curr = "";
        helper(s, i + 1, curr, st, res);
        if (--st[prev] == 0) st.erase(prev);
        curr = prev;

        if (i < s.size() - 1) {
            helper(s, i + 1, curr, st, res);
        }
        
        curr.pop_back();
    }
};