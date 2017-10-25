/*
Given string A representative a positive integer which has N digits, 
remove any k digits of the number, the remaining digits are arranged 
according to the original order to become a new positive integer.

Find the smallest integer after remove k digits.

N <= 240 and k <= N,

Example
Given an integer A = "178542", k = 4

return a string "12"
 */

class Solution {
public:
    /*
     * @param A: A positive integer which has N digits, A is a string
     * @param l: Remove k digits
     * @return: A string
     */
    string DeleteDigits(string &A, int l) {
        // write your code here
        int n = A.size();
        string res = "";
        res += keepKDigits(A, 0, n - l);
        if (res == "") return "0";
        else {
            int idx = 0;
            while (res[idx] == '0')
                ++idx;
            res = res.substr(idx);
            if (res == "") return "0";
            else return res;
        }
    }

private:

    string keepKDigits(string& nums, int start, int k) {
        int n = nums.size();
        if (k == 0) return "";
        if (n - start == k) return nums.substr(start);
        string res = "";
        char tmp = nums[start];
        int min_idx = start;
        for (int i = start + 1; i < n - k + 1; ++i) {
            if (nums[i] < tmp) {
                tmp = nums[i];
                min_idx = i;
            }
        }
        res += tmp;
        return res + keepKDigits(nums, min_idx + 1, k - 1);
    }
};
