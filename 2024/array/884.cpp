class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m1, m2;
        istringstream is1(s1), is2(s2);
        string token;
        while (is1 >> token) {
            m1[token]++;
        }
        while (is2 >> token) {
            m2[token]++;
        }

        vector<string> res;

        for (pair<const string, int> &p : m1) {
            if (p.second != 1) continue;
            if (!m2.count(p.first)) res.push_back(p.first);
        }

        for (pair<const string, int> &p : m2) {
            if (p.second != 1) continue;
            if (!m1.count(p.first)) res.push_back(p.first);
        }

        return res;
    }
};