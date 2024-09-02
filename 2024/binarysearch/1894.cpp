class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long> prefix(n, 0);
        prefix[0] = chalk[0];
        for (int i = 1; i < n; i++) prefix[i] = chalk[i] + prefix[i-1];
        k %= prefix[n-1];

        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] <= k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};