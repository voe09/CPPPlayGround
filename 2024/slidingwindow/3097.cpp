class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(32, 0);

        int l = 0, r = 0;
        int mn = INT_MAX;
        for (; r < n; r++) {
            update(bits, nums[r], true);
            while (l <= r && count(bits) >= k) {
                mn = min(mn, r - l + 1);
                update(bits, nums[l++], false);
            }
        }

        return mn == INT_MAX ? -1 : mn;
    }

private:
    int count(vector<int> &bits) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] == 0) continue;
            res |= (1 << i);
        }
        return res;
    }

    void update(vector<int> &bits, int num, bool add) {
        for (int i = 0; num > 0; i++) {
            if (add) bits[i] += (num & 1);
            else bits[i] -= (num & 1);
            num >>= 1;
        }
    }

};