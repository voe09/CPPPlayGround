/*
Given an integer n, find the closest integer (not including itself),
which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:
Input: "123"
Output: "121"
Note:
The input n is a positive integer represented by string, whose
length will not exceed 18.
If there is a tie, return the smaller one as answer.
 */
class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.empty()) return n;
        if (n.size() == 1) {
            if (n == "0") return "1";
            else {
                n[0] -= 1;
                return n;
            }
        }
        int length = n.size();
        n.resize(length + length - 1);
        int j = length - 1;
        for (int i = length + length - 2; i >= 0; --i) {
            n[i--] = n[j--];
            if (i > 0) {
                n[i] = '*';
            }
        }

        string left = n;
        string right = n;
        int l = 0, r = 2 * length - 2;
        while (l <= r) {
            left[r] = left[l];
            right[l] = right[r];
            ++l, --r;
        }

        int current_idx = 0;
        for (int i = 0; i < left.size(); ++i) {
            if (left[i] != '*') {
                left[current_idx] = left[i];
                right[current_idx] = right[i];
                ++current_idx;
            }
        }

        left.resize(current_idx);
        right.resize(current_idx);

        return (right[0] != '0' && left > right) ? right : left;
    }
};


/*
那么如何将一个不是回文数的数变成回文数呢，我们有两种选择，要么改变左半边，
要么改变右半边。由于我们希望和原数绝对差最小，肯定是改变低位上的数比较好，
所以我们改变右半边，那么改变的情况又分为两种，一种是原数本来就是回文数，
这种情况下，我们需要改变中间的那个数字，要么增加1，要么减小1，比如121，
可以变成111和131。另一种情况是原数不是回文数，我们只需要改变右半边就行了，
比如123，变成121。那么其实这三种情况可以总结起来，分别相当于对中间的2进行了-1, 
+1, +0操作，那么我们就可以用一个-1到1的for循环一起处理了，
先取出包括中间数的左半边，比如123就取出12，1234也取出12，然后就要根据左半边
生成右半边，为了同时处理奇数和偶数的情况，我们使用一个小tricky，在反转复制左半边
的时候，我们给rbegin()加上len&1，当奇数时，len&1为1，这样就不会复制中间数了；
为偶数时，len&1为0，这就整个翻转复制了左半边。我们把每次生成的回文串转为转为数字
后加入到一个集合set中，把之前的两个边界值也同样加进去，最后我们在五个candidates
中找出和原数绝对差最小的那个返回，记得别忘了在集合中删除原数，因为如果原数时回文的话, i=0时就把自己也加入集合了
 */

class Solution {
public:
    string nearestPalindromic(string n) {
        long len = n.size(), num = stol(n), res, minDiff = LONG_MAX;
        unordered_set<long> s;
        s.insert(pow(10, len) + 1);
        s.insert(pow(10, len - 1) - 1);
        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (long i = -1; i <= 1; ++i) {
            string pre = to_string(prefix + i);
            string str = pre + string(pre.rbegin() + (len & 1), pre.rend());
            s.insert(stol(str));
        }
        s.erase(num);
        for (auto a : s) {
            long diff = abs(a - num);
            if (diff < minDiff) {
                minDiff = diff;
                res = a;
            } else if (diff == minDiff) {
                res = min(res, a);
            }
        }
        return to_string(res);
    }
};
