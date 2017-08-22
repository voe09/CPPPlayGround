/*
Given integers n and k, find the lexicographically k-th smallest integer in the 
range from 1 to n.

Note: 1 ≤ k ≤ n ≤ 109.

Example:

Input:
n: 13   k: 2

Output:
10

Explanation:
The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], 
so the second smallest number is 10.
 */

/*
是个十叉树Denary Tree，就是每个节点的子节点可以有十个，比如数字1的子节点就是10
到19，数字10的子节点可以是100到109，但是由于n大小的限制，构成的并不是一个满十叉树
这道题实际上就变成了一个先序遍历十叉树的问题，那么难点就变成了如何计算出每个节点的子节点的个数
不停的用k减去子节点的个数，当k减到0的时候，当前位置的数字即为所求
现在我们来看如何求子节点个数，比如数字1和数字2，我们要求按字典遍历顺序从1到2需要
经过多少个数字，首先把1本身这一个数字加到step中，然后我们把范围扩大十倍，范围变成
10到20之前，但是由于我们要考虑n的大小，由于n为13，所以只有4个子节点，这样我们就
知道从数字1遍历到数字2需要经过5个数字，然后我们看step是否小于等于k，
如果是，我们cur自增1，k减去step；如果不是，说明要求的数字在子节点中，
我们此时cur乘以10，k自减1，以此类推，直到k为0推出循环，此时cur即为所求
*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            long long step = 0, first = cur, last = cur + 1;
            while (first <= n) {
                step += min((long long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }
            if (step <= k) {
                ++cur;
                k -= step;
            } else {
                cur *= 10;
                --k;
            }
        }
        return cur;
    }
};

class Solution {
public:
    int findKthNumber(int n, int k) {
        int result = 0;

        vector<int> cnts(10);
        for (int i = 1; i <= 9; ++i) {
            cnts[i] = cnts[i - 1] * 10 + 1;
        }

        vector<int> nums;
        for (int i = n; i > 0; i /= 10) {
            nums.emplace_back(i % 10);
        }
        int total = n;
        int target = 0;
        for (int i = nums.size() - 1; i >= 0 && k; --i) {
            target = target * 10 + nums[i];
            const auto start = i == nums.size() - 1 ? 1 : 0;
            for (int j = start; j <= 9; ++j) {
                const auto candidate = result * 10 + j;
                int num;
                if (candidate < target) {
                    num = cnts[i + 1];
                } else if (candidate > target) {
                    num = cnts[i];
                } else {
                    num = total - cnts[i + 1] * (j - start) - cnts[i] * (9 - j);
                }
                if (k > num) {
                    k -= num;
                } else {
                    result = candidate;
                    --k;
                    total = num - 1;
                    break;
                }
            }
        }
        return result;
    }
};
