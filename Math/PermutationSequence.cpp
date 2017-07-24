/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {;
       vector<int> nums;
       for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
       }
       --k;
       return getPermutation(nums, k);
    }

private:
    int permutation(int n) {
        int res = 1;
        while (n >= 1) {
            res *= n--;
        }
        return res;
    }

    string getPermutation(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return "";
        }
        
        int perm = permutation(n - 1);
        int carry = k / perm;
        k %= perm;
        string res = to_string(nums[carry]);
        nums.erase(nums.begin() + carry);
        res = res + getPermutation(nums, k);
        return res;
    }
};


