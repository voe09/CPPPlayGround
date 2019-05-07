/*
Given scores of N athletes, find their relative ranks and the people with the 
top three highest scores, who will be awarded medals: "Gold Medal", 
"Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, 
so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks
according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
 */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        vector<string> res (n, "");
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompPair> heap;
        for (int i = 0; i < n; ++i) {
            heap.push({i, nums[i]});
        }
        int cnt = 0;
        while (!heap.empty()) {
            pair<int, int> tmp = heap.top();
            heap.pop();
            ++cnt;
            if (cnt == 1) res[tmp.first] = "Gold Medal";
            else if (cnt == 2) res[tmp.first] = "Silver Medal";
            else if (cnt == 3) res[tmp.first] = "Bronze Medal";
            else res[tmp.first] = to_string(cnt);
        }
        return res;
    }

private:
    struct CompPair {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        }
    };
};
