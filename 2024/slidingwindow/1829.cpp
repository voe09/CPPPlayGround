class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> bits(maximumBit, 0);
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            update(bits, nums[i], maximumBit);
            res.push_back(getComplement(bits, maximumBit));
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void update(vector<int> &bits, int num, int mx) {
        for (int i = 0; i < mx; i++) {
            bits[i] ^= (num & 1);
            num >>= 1;
        }
    }

    int getComplement(vector<int> &bits, int mx) {
        int comp = (1 << mx) - 1;
        int res = 0;
        for (int i = 0; i < mx; i++) {
            if (bits[i] == 0) continue;
            res |= (1 << i);
        }
        return comp ^ res;
    }
};