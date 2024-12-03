class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(), spaces.end());
        string res;
        int start = 0;
        for (int end : spaces) {
            res += s.substr(start, end - start) + " ";
            start = end;
        }
        res += s.substr(start);
        return res;
    }
};