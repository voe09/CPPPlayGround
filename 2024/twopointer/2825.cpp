class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            if (str1[i] == str2[j]) {
                i++, j++;
            } else {
                char c = str1[i] + 1;
                cout << c << endl;
                if (c > 'z')
                    c -= 26;
                cout << "post: " << c << endl;
                if (c == str2[j])
                    i++, j++;
                else
                    i++;
            }
        }

        return j == str2.size();
    }
};