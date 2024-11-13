class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        sort(nums.begin(), nums.end());
        int r = nums.size();
        for (int i = 0; i < nums.size() - 1; i++) {
            int l = i + 1;
            // find r where r is the last nums[r - 1] + nums[i] <= upper
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (nums[i] + nums[mid] > upper) r = mid;
                else l = mid + 1; 
            }

            // find l where l is the first nums[l] + nums[i] >= lower
            l = i + 1;
            int t = r;
            while (l < t) {
                int mid = l + (t - l) / 2;
                if (nums[i] + nums[mid] < lower) l = mid + 1;
                else t = mid;
            }
            if (l < r) res += (r - l);
        }
        return res;
    }
};