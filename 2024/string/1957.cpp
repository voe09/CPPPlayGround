class Solution {
public:
    string makeFancyString(string s) {
        string res;
        if (s.size() < 2) return s;
        res.push_back(s[0]);
        res.push_back(s[1]);
        for (int k = 2; k < s.size(); k++) {
            int i = res.size() - 1, j = res.size() - 2;
            if (res[i] == res[j] && res[i] == s[k]) continue;
            res.push_back(s[k]);
        }
        return res;
    }
};