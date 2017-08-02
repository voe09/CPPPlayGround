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

对于数组中的任意整数K，很容易通过算式loc = (K - A) / len找出其桶的位置，然后维护每一个桶的最大值和最小值

由于同一个桶内的元素之间的差值至多为len - 1，因此最终答案不会从同一个桶中选择。

对于每一个非空的桶p，找出下一个非空的桶q，则q.min - p.max可能就是备选答案。返回所有这些可能值中的最大值。
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {

    }
};
