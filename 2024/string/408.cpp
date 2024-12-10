class Solution {
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        // write your code here
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (word[i] == abbr[j]) i++, j++;
            else {
                if (abbr[j] < '0' || abbr[j] > '9') return false;
                int cnt = 0;
                if (abbr[j] == '0') return false;
                while (j < abbr.size() && abbr[j] >= '0' && abbr[j] <= '9') cnt = cnt * 10 + (abbr[j++] - '0');
                i += cnt;
            }
        }

        return i == word.size() && j == abbr.size();
    }
};
