/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (len <= numRows || numRows == 1) return s;
        string res = "";
        for (int row = 0; row < numRows; ++row) {
            if (row == 0 || row == numRows - 1) {
                int i = row;
                do {
                    res += s[i];
                    i += 2 * numRows - 2;
                } while (i < len);
            } else {
                int i = row;
                do {
                    res += s[i];
                    if (i + 2 * (numRows - 1 - row) < len)
                        res += s[i + 2 * (numRows - 1 - row)];
                    else
                        break;
                    i += 2 * numRows - 2;
                } while (i < len);
            }
        }
        return res;
    }
};
