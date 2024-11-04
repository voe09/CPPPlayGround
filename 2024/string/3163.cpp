class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";
        string comp;
        for (int i = 0; i < word.size();) {
            int cnt = 1;
            char curr = word[i];
            i++;
            while (i < word.size() && cnt < 9 && word[i] == curr) {
                cnt++, i++;
            }
            comp.push_back('0' + cnt);
            comp.push_back(curr);
        }
        return comp;
    }
};