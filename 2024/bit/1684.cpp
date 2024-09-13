class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int voc = 0;
        for (char c : allowed) voc = (voc | (1 << (c - 'a')));
        int res = 0;
        for (string &w : words) {
            bool consis = true;
            for (char c : w) {
                if ((voc & (1 << (c - 'a'))) == 0) {
                    consis = false;
                    break;
                }
            }

            res += consis ? 1 : 0;
        }
        return res;
    }
};