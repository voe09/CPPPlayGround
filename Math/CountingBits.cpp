/*
Given a non negative integer number num. For every numbers i in the range 
0 ≤ i ≤ num calculate the number of 1's in their binary representation and 
return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like 
__builtin_popcount in c++ or in any other language.
*/


// http://www.cnblogs.com/grandyang/p/5294255.html
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res {0};
        if (num == 0) return res;
        res.push_back(1);
        if (num == 1) return res;
        int i = 1;
        while (pow(2, i) <= num) {
            int start = pow(2, i);
            int end = pow(2, i+1);
            int dis = (end - start) / 2;
            int mid = start + dis;
            if (num >= end) {
                while (start < mid) {
                    res.push_back(res[start - dis]);
                    ++start;
                }
                while (start < end) {
                    res.push_back(res[start - dis] + 1);
                    ++start;
                }
            } else {
                if (num < mid) {
                    while (start <= num) {
                        res.push_back(res[start - dis]);
                        ++start;
                    }
                } else {
                    while (start < mid) {
                        res.push_back(res[start - dis]);
                        ++start;
                    }

                    while (start <= num) {
                        res.push_back(res[start - dis] + 1);
                        ++start;
                    }
                }
            }
            ++i;
        }
        return res; 
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return {0};
        vector<int> res{0, 1};
        int k = 2, i = 2;
        while (i <= num) {
            for (i = pow(2, k - 1); i < pow(2, k); ++i) {
                if (i > num) break;
                int t = (pow(2, k) - pow(2, k - 1)) / 2;
                if (i < pow(2, k - 1) + t) res.push_back(res[i - t]);
                else res.push_back(res[i - t] + 1);
            }
            ++k;
        }
        return res;
    }
};
