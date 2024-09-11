class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<long> presum(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            presum[i] += presum[i-1];
        }

        long res = 0, M = 1e9 + 7;

        for (int i = 0; i < n - 2; i++) {
            long left = i+1, right = n;
            // find the 1st number presum[x] - presum[i] >= presum[i]
            while (left < right) {
                long mid = left + (right - left) / 2;
                if (presum[mid] - presum[i] < presum[i]) left = mid + 1;
                else right = mid;
            }

            long l = right;

            // find the 1st number presum[n - 1] - presum[mid] < presum[mid] - presum[i]
            left = l, right = n - 1;
            while (left < right) {
                long mid = left + (right - left) / 2;
                if (presum[n-1] - presum[mid] < presum[mid] - presum[i]) right = mid;
                else left = mid + 1;
            }

            long r = right;
            res = (res + max(r - l, 0l)) % M;
        }
        return res;
    }
};