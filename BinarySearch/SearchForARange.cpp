/*
Given an array of integers sorted in ascending order, 
find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 */

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        const int begin = lower_bound(nums, target);
        const int end = upper_bound(nums, target);

        if (begin < nums.size() && nums[begin] == target) {
            return {begin, end - 1};
        }

        return {-1, -1};
    }

private:
    int lower_bound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        // Find min left s.t. A[left] >= target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int upper_bound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        // Find min left s.t. A[left] > target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
       if(n == 0) {
            return vector<int>({-1, -1});
        }

        vector<int> v;
        int low = 0;
        int high = n - 1;
        //第一次二分找第一个位置
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(A[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(low < n && A[low] == target) {
            v.push_back(low);
        } else {
            return vector<int>({-1, -1});
        }

        low = low;
        high = n - 1;
        //从第一个位置开始进行第二次二分，找最后一个位置
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(A[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        v.push_back(high);
        return v;
    }
};

// Binary Search With Duplicates

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        vector<int> res;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        if (low < nums.size() && nums[low] == target)
            res.push_back(low);
        else
            return {-1, -1};

        high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        res.push_back(high);
        return res;
    }
};
