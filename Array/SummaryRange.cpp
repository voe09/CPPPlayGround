/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        if (nums.size() == 1) {
            string tmp = to_string(nums[0]);
            res.push_back(tmp);
            return res;
        }
        int start = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                if (start != nums[i - 1]) {
                    res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                    start = nums[i];
                } else {
                    res.push_back(to_string(start));
                    start = nums[i];
                }

            }
        }
        int end = nums[nums.size() - 1];
        if (start != end) {
            res.push_back(to_string(start) + "->" + to_string(end));
        } else {
            res.push_back(to_string(start));
        }
        
        return res;
    }
};
