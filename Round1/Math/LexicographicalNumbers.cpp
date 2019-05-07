/*
 * Given an integer n, return 1 - n in lexicographical order.
 *
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 *
 * Please optimize your algorithm to use less time and space. 
 * The input size may be as large as 5,000,000.
 */

// http://www.cnblogs.com/grandyang/p/5798275.html 
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            DFS(i, n, res);
        }
        return res;
    }

    void DFS(int i, int n, vector<int> &res) {
        if (i > n) return;
        res.push_back(i);
        for (int j = 0; j <= 9; ++j) {
            DFS(i * 10 + j, n, res);
        }
    }
};

// 本质上其实一样，就是non iterative，比较难理解
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                if (cur >= n) cur /= 10;
                cur += 1;
                while (cur % 10 == 0) cur /= 10;
            }
        }
        return res;
    }
};
