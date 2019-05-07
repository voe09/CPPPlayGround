/*
Given n pieces of wood with length L[i] (integer array). 
Cut them into small pieces to guarantee you could have equal
or more than k pieces with the same length. What is the longest 
length you can get from the n pieces of wood? Given L & k, 
return the maximum length of the small pieces.

You couldn't cut wood into float length.

If you couldn't get >= k pieces, return 0.

Have you met this question in a real interview? Yes
Example
For L=[232, 124, 456], k=7, return 114.

Challenge 
O(n log Len), where Len is the longest length of the wood.
 */

/*
这道题要直接想到二分搜素其实不容易，但是看到题中 Challenge 的提示后
你大概就能想到往二分搜索上靠了。首先来分析下题意，题目意思是说给出
n 段木材L[i], 将这 n 段木材切分为至少 k 段，这 k 段等长，
求能从 n 段原材料中获得的最长单段木材长度。以 k=7 为例，
要将 L 中的原材料分为7段，能得到的最大单段长度为114, 232/114 = 2,
124/114 = 1, 456/114 = 4, 2 + 1 + 4 = 7.
理清题意后我们就来想想如何用算法的形式表示出来，显然在计算如2, 1, 4等分片数时
我们进行了取整运算，在计算机中则可以使用下式表示：
∑i=1nL[i]l≥k\sum _{i = 1} ^{n} \frac {L[i]}{l} \geq k∑i=1nlL[i]≥k
其中 lll 为单段最大长度，
显然有 1≤l≤max(L[i])1 \leq l \leq max(L[i])1≤l≤max(L[i]). 
单段长度最小为1，最大不可能超过给定原材料中的最大木材长度。

****> 注意求和与取整的顺序，是先求 L[i]/l的单个值，而不是先对L[i]求和。
分析到这里就和题 Sqrt x 差不多一样了，要求的是 lll 的最大可能取值，同时 lll 可以看做是从有序序列[1, max(L[i])]的一个元素，典型的二分搜素！
 */


class Solution {
public:
    /*
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int CountPiece(vector<int> &L, int x) {
        int cnt = 0;
        for (int i = 0; i < L.size(); ++i) {
            cnt += L[i] / x;
        }
        return cnt;
    }

    int woodCut(vector<int> &L, int k) {
        // write your code here
        if (L.empty()) return 0;
        int left = 1, right = *max_element(L.begin(), L.end());
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (CountPiece(L, mid) < k) right = mid - 1;
            else left = mid + 1;
        }
        return left - 1;
    }
};

// Time:  O(nlogL)
// Space: O(1)

class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        const int n = L.size();
        if (n == 0) {
            return 0;
        }

        int left = 1, right = *max_element(L.cbegin(), L.cend());
        while (left <= right) {
            const auto mid = left + (right - left) / 2;

            // Find the smallest x,  s.t. pieceCount(x) < k <= pieceCound(x - 1)
            if (pieceCount(L, mid) < k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // The max length is x - 1
        return left - 1;
    }

private:
    int pieceCount(vector<int>& L, int x) {
        int cnt = 0;
        for (const auto& len : L) {
            cnt += len / x;
        }
        return cnt;
    }
};
