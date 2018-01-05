/*
Given a list of non negative integers, arrange them such that they
form the largest number.

 Notice

The result may be very large, so you need to return a 
string instead of an integer.

Have you met this question in a real interview? Yes
Example
Given [1, 20, 23, 4, 8], the largest formed number is 8423201.

Challenge 
Do it in O(nlogn) time complexity.
 */

class Solution {
public:
    /*
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end(), [](int &a, int &b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        string res;
        for (const auto &num : nums) {
            res += to_string(num);
        }
        int start = 0;
        for (; start < res.size() - 1; ++start) {
            if (res[start] != '0') break;
        }
        
        res = res.substr(start);
        return res;
    }
};
