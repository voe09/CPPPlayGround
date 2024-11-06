// bubble sort
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num : nums) {cnts[num] = countBits(num);}

        int n = nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 1; j--) {
                if (nums[j] >= nums[j-1]) continue;
                if (cnts[nums[j]] != cnts[nums[j-1]]) return false;
                swap(nums[j], nums[j-1]);
            }
        }

        return true;
    }

private:
    int countBits(int num) {
        int cnt = 0;
        while (num > 0) {
            cnt += (num & 1);
            num >>= 1;
        }
        return cnt;
    }
};

// segmentation
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int numBits = countBits(nums[0]);
        int mn = nums[0], mx = nums[0];
        int prevMx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (countBits(nums[i]) == numBits) {
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
            } else {
                if (mn < prevMx) return false;
                prevMx = mx;
                numBits = countBits(nums[i]);
                mn = nums[i], mx = nums[i];
            }
        }

        return prevMx < mn;
    }

private:
    int countBits(int num) {
        int cnt = 0;
        while (num > 0) {
            cnt += (num & 1);
            num >>= 1;
        }
        return cnt;
    }
};