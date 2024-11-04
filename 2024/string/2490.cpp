class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence.size() <= 1) return true;
        if (sentence[0] != sentence[sentence.size() - 1]) return false;
        for (int i = 0, j = 1; j < sentence.size(); i++, j++) {
            while (j < sentence.size() && sentence[j] != ' ') i++, j++;
            if (j < sentence.size()) {
                if (sentence[i] != sentence[j+1]) return false;
            }
        }
        return true;
    }
};