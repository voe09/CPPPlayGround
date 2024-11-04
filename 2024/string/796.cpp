class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string source = s + s;
        return source.find(goal) < source.length();
    }
};