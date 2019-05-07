/*
Given an unsorted array, find the maximum difference between the successive 
elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in 
the 32-bit signed integer range.
 */

/*
假设有N个元素A到B。

那么最大差值不会小于ceiling[(B - A) / (N - 1)]

令bucket（桶）的大小len = ceiling[(B - A) / (N - 1)]，则最多会有(B - A) / len + 1个桶

对于数组中的任意整数K，很容易通过算式loc = (K - A) / len找出其桶的位置，
然后维护每一个桶的最大值和最小值

由于同一个桶内的元素之间的差值至多为len - 1，因此最终答案不会从同一个桶中选择。

对于每一个非空的桶p，找出下一个非空的桶q，则q.min - p.max可能就是备选答案。返回所有这些可能值中的最大值。
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return 0;
        int max = INT_MIN, min = INT_MAX;
        for (const auto& num: nums) {
            if (num < min) min = num;
            if (num > max) max = num;
        }

        int bucket_size = (max - min) / (length - 1);
        int num_bucket = (max - min) / bucket_size + 1;
        vector<vector<int>> buckets(num_bucket);

        for (const auto& num: nums) {
            int bucket_idx = (num - min) / bucket_size;
            insertInBucket(buckets[bucket_idx], num);
        }

        int max_gap = INT_MIN;
        for (int i = 0, j = 1; i < num_bucket && j < num_bucket; ++i, ++j) {
            while (buckets[i].empty())
                ++i;
            while (j <= i || buckets[j].empty())
                ++j;
            max_gap = std::max(max_gap, buckets[j][0] - buckets[i].back());
        }
        return max_gap;
    }

private:
    void insertInBucket(vector<int>& nums, int num) {
        auto it = nums.begin();
        for (;it != nums.end(); ++it) {
            if (*it >= num) break;
        }
        nums.insert(it, num);
    }
};
