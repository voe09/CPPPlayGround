class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream is(sentence);
        string token;
        int cnt = 1;
        while (is >> token) {
            if (isPrefix(token, searchWord)) return cnt;
            cnt++;
        }
        return -1;
    }

    bool isPrefix(string &word, string &token) {
        if (word.size() < token.size()) return false;
        for (int i = 0; i < token.size(); i++) {
            if (word[i] != token[i]) return false;
        }
        return true;
    }
};