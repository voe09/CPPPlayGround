/*
You have a number of envelopes with widths and heights given as a pair of 
integers (w, h). One envelope can fit into another if and only if both the 
width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes 
you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
 */

// http://www.cnblogs.com/grandyang/p/5568818.html

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        int res = 0, length = envelopes.size();
        vector<int> dp(length, 0);
        sort(envelopes.begin(), envelopes.end());
        dp[0] = 1;
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first &&
                    envelopes[i].second > envelopes[j].second)
                    dp[i] = max(dp[i], dp[j] + 1);
                else
                    dp[i] = max(dp[i], 1);
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};
