class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> nums(banned.begin(), banned.end());
        int cnt = 0;
        int sum = 0;
        for (int i = 1; i <= n && sum <= maxSum; i++) {
            if (nums.count(i)) continue;
            cnt++;
            sum += i;
        }
        return sum <= maxSum ? cnt : cnt - 1;
    }
};