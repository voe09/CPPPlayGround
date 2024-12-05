class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int l = 0, r = 0;
        while (l < n || r < n) {
            while (l < n && start[l] == '_')
                l++;
            while (r < n && target[r] == '_')
                r++;
            if (l == n || r == n) {
                return l == n && r == n;
            }

            if (start[l] != target[r] || (start[l] == 'L' && l < r) ||
                (start[l] == 'R' && l > r))
                return false;
            l++, r++;
        }
        return true;
    }
};