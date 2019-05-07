/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        
    }
};


/*
如果n是num的长度，我们要去除k个，那么需要剩下n-k个，我们开始遍历给定数字num的
每一位，对于当前遍历到的数字c，进行如下while循环，如果res不为空，且k大于0，且
res的最后一位大于c，那么我们应该将res的最后一位移去，且k自减1。当跳出while循环
后，我们将c加入res中，最后我们将res的大小重设为n-k。根据题目中的描述，可能会出
现"0200"这样不符合要求的情况，所以我们用一个while循环来去掉前面的所有0，然后返
回时判断是否为空，为空则返回“0”
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size(), keep = n - k;
        for (char c : num) {
            while (k && res.size() && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(keep);
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};

/*
The idea is based on the fact that a character among first (n+1) characters must be there in resultant number. So we pick the smallest of first (n+1) digits and put it in result, and recur for remaining characters. Below is complete algorithm.

Initialize result as empty string
     res = ""
buildLowestNumber(str, n, res)
1) If n == 0, then there is nothing to remove.
   Append the whole 'str' to 'res' and return

2) Let 'len' be length of 'str'. If 'len' is smaller or equal 
   to n, then everything can be removed
   Append nothing to 'res' and return

3) Find the smallest character among first (n+1) characters
   of 'str'.  Let the index of smallest character be minIndex.
   Append 'str[minIndex]' to 'res' and recur for substring after
   minIndex and for n = n-minIndex

     buildLowestNumber(str[minIndex+1..len-1], n-minIndex).
*/


class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string res = "";
        res += keepKdigits(num, 0, n - k);
        if (res == "") return "0";
        else {
            int idx = 0;
            while (res[idx] == '0') {
                ++idx;
            }
            res = res.substr(idx);
            if (res == "") return "0";
            else return res;
        }
    }
    
private:
    string keepKdigits(string& num, int start, int k) {
        int n = num.size();
        if (k == 0) return "";
        if (n - start == k) return num.substr(start);
        string res = "";
        char tmp = num[start];
        int min_idx = start;
        for (int i = start + 1; i < n - k + 1; ++i) {
            if (num[i] < tmp) {
                tmp = num[i];
                min_idx = i;
            }
        }
        res += tmp;
        return res + keepKdigits(num, min_idx + 1, k - 1);
    }    
};
