/*
Given an array of words and a length L, format the text such that each line 
has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words 
as you can in each line. Pad extra spaces ' ' when necessary 
so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, 
the empty slots on the left will be assigned more spaces 
than the slots on the right.

For the last line of text, 
it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. 
What should you do in this case?
In this case, that line should be left-justified.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (words.empty()) return res;
        vector<string> tmp;
        int len = 0;
        for (auto& word: words) {
            if (len + word.size() <= maxWidth) {
                tmp.push_back(word);
                len += word.size() + 1;
            } else {
                string row = rowJustify(tmp, maxWidth);
                res.push_back(row);
                tmp.clear();
                tmp.push_back(word);
                len = word.size() + 1;
            }
        }
        string row = leftJustify(tmp, maxWidth);
        res.push_back(row);
        return res;
    }

private:
    string leftJustify(string& word, int maxWidth) {
        string res(maxWidth, ' ');
        for (int i = 0; i < word.size(); ++i) {
            res[i] = word[i];
        }
        return res;
    }

    string leftJustify(vector<string>& words, int maxWidth) {
        string res(maxWidth, ' ');
        int i = 0;
        for (auto& word: words) {
            for (int j = 0; j < word.size(); ++j) {
                res[i] = word[j];
                ++i;
            }
            ++i;
        }
        return res;
    }

    string rowJustify(vector<string>& words, int maxWidth) {
        string res(maxWidth, ' ');
        int len = 0;
        int count = 0;
        for (auto& word: words) {
            len += word.size();
            ++count;
        }
        if (count == 1) return leftJustify(words[0], maxWidth);
        int space_len = maxWidth - len;
        int avg_space = space_len / (count - 1);
        int addition_space = space_len % (count - 1);
        
        int i = 0;
        for (auto& word: words) {
            for (int j = 0; j < word.size(); ++j) {
                res[i] = word[j];
                ++i;
            }
            if (i < maxWidth) {
                i += avg_space;
                i += (addition_space > 0) ? 1 : 0;
                addition_space -= 1;
            }
        }
        return res;
    }
};
