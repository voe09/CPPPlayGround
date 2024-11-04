class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string curr = "";
        helper(curr, n, res);
        return res;
    }

private:
    void helper(string &curr, int n, vector<string> &res) {
        int t = curr.size();
        if (t == n) {
            res.push_back(curr);
            return;
        }

        if (curr.empty() || curr[t - 1] == '1') {
            curr.push_back('0');
            helper(curr, n, res);
            curr.pop_back();
        }

        curr.push_back('1');
        helper(curr, n, res);
        curr.pop_back();
    }
};