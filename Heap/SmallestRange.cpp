/*
You have k lists of sorted integers in ascending order. Find the smallest range
that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.
 */
// https://leetcode.com/articles/smallest-range/

/*
1. Initialize next array with all 0's (mean now only considering first element in all lists)
2. Find the indices of the lists containing the minumum and maxmum values elements amongst the elements pointed by the next array
3. If the range formed by the maximum and minimum elements found above is larger than the previous maximum range, update the boundary values used for the maximum range
4. Increment the pointer nums[min];
5. Repeat steps 2 to 4 till any of the lists get exhausted

idea:
首先我们考虑所有lists里最小的数，在这些数里选出min和max，这时[min, max]就包含了至少1个数在每个list里
为了缩小范围，我们有两种选择，增大min或者缩小max，但是现在max已经是最小的了，不能更小，
所以我们只能考虑增大min，所以我们把min所在的list的next增大1，然后update min和max，以此类推直到某个list被全部扫完
 */


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> next (n, 0);
        pq heap;
        int minVal = INT_MAX, maxVal = INT_MIN;
        int resMin, resMax;
        for (int i = 0; i < n; ++i) {
            minVal = min(minVal, nums[i][next[i]]);
            maxVal = max(maxVal, nums[i][next[i]]);
            heap.push({i, nums[i][next[i]]});
        }
        resMin = minVal, resMax = maxVal;

        while (true) {
            pair<int, int> tmp = heap.top();
            heap.pop();
            ++next[tmp.first];
            if (next[tmp.first] == nums[tmp.first].size()) break;
            int curr = nums[tmp.first][next[tmp.first]];
            maxVal = max(maxVal, curr);
            heap.push({tmp.first, curr});
            minVal = heap.top().second;
            if (maxVal - minVal < resMax - resMin) {
                resMax = maxVal;
                resMin = minVal;
            }
        }
        return {resMin, resMax};
    }

private:
    struct CompairPair {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    typedef priority_queue<pair<int, int>, vector<pair<int, int>>, CompairPair> pq;
};
