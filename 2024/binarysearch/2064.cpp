class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = 0;
        for (int q : quantities) r = max(r, q);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (!distribute(n, quantities, mid)) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    bool distribute(int n, vector<int> &qs, int mx) {
        int cnt = 0;
        for (int q : qs) cnt += (q % mx == 0) ? q / mx : q / mx + 1;
        return cnt <= n;
    }
};