// TLE solution
class Solution {
public:
    int minChanges(string s) {
        if (s.size() == 2) {
            return s[0] == s[1] ? 0 : 1;
        }
        if (m.count(s)) return m[s];

        int res = INT_MAX;
        for (int i = 2; i < s.size(); i += 2) {
            res = min(res, minChanges(s.substr(0, i)) + minChanges(s.substr(i)));
        }

        m[s] = res;
        return res;
    }

private:
    map<string, int> m;
};