/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/
// Moore Voting
/*
Initialize an element m and a counter i with i = 0
For each element x of the input sequence:
If i = 0, then assign m = x and i = 1
else if m = x, then assign i = i + 1
else assign i = i − 1
Return m
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int m = 0, n = 0, cm =0, cn = 0;
        for (auto &num: nums) {
            if (num == m) ++cm;
            else if (num == n) ++cn;
            else if (cm == 0) m = num, cm = 1;
            else if (cn == 0) n = num, cn = 1;
            else --cm, --cn;
        }
        cm = cn = 0;
        for (auto &num: nums) {
            if (num == m) ++cm;
            else if (num == n) ++cn;
        }
        if (cm > nums.size() / 3) res.push_back(m);
        if (cn > nums.size() / 3) res.push_back(n);
        return res;
    }
};
