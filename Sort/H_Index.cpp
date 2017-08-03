/*
Given an array of citations (each citation is a non-negative integer) of a 
researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h 
if h of his/her N papers have at least h citations each, and the other N − h 
papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher 
has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations 
respectively. Since the researcher has 3 papers with at least 3 citations 
each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken 
as the h-index.
 */


// Count sort: citation > length是不可能成为h index的所以把他们放到一个bucket里
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        vector<int> count(length + 1, 0);
        for (const auto& citation : citations) {
            if (citation >= length) {
                ++count[length];
            } else {
                ++count[citation];
            }
        }

        int h = 0;
        for (int i = length; i >= 0; --i) {
            h += count[i];
            if (h >= i) return i;
        }
        return h;
    }
};

// Count sort
vector<int> nums; // positive
get max from nums;
vector<int> counts(max + 1, 0);
for (num: nums) ++counts[num];
for (int i = 1; i < max + 1; ++i) {
    counts[i] += counts[i - 1];
}
vector<int> res(length, 0);
for (num: nums) {
    res[counts[num]] = num;
    --counts[num];
}
return res;
