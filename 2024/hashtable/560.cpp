class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int res = 0;
        for (int num : nums) {
            sum += num;
            int target = sum - k;
            res += m[target];
            m[sum]++;
        }
        return res;
    }
};