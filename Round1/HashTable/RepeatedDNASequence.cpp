/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to 
identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) 
that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

// http://www.cnblogs.com/grandyang/p/4284205.html

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> res, st;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string t = s.substr(i, 10);
            if (st.count(t)) res.insert(t);
            else st.insert(t);
        }
        return vector<string>{res.begin(), res.end()};
    }
};


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        unordered_map<int, int> m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int cur = 0, i = 0;
        while (i < 9) cur = cur << 2 | m[s[i++]];
        while (i < s.size()) {
            cur = ((cur & 0x3ffff) << 2) | (m[s[i++]]);
            if (st.count(cur)) res.insert(s.substr(i - 10, 10));
            else st.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};
