/*
You have n super washing machines on a line. Initially, each washing machine
has some dresses or is empty.

For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass
one dress of each washing machine to one of its adjacent washing machines at
the same time .

Given an integer array representing the number of dresses in each washing 
machine from left to right on the line, you should find the minimum number
of moves to make all the washing machines have the same number of dresses. 
If it is not possible to do it, return -1.

Example1

Input: [1,0,5]

Output: 3

Explanation: 
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
3rd move:    2     1 <-- 3    =>    2     2     2   
Example2

Input: [0,3,0]

Output: 2

Explanation: 
1st move:    0 <-- 3     0    =>    1     2     0    
2nd move:    1     2 --> 0    =>    1     1     1     
Example3

Input: [0,2,0]

Output: -1

Explanation: 
It's impossible to make all the three washing machines have the same number of dresses. 
Note:
The range of n is [1, 10000].
The range of dresses number in a super washing machine is [0, 1e5].
 */

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        if (machines.empty()) return 0;
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (sum % n != 0) return -1;
        int avg = sum / n;
        vector<int> needs(machines);
        for (int i = 0; i < n; ++i) {
            needs[i] -= avg;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (needs[i] > 0) {
                while (needs[j] >= 0) ++j;
                while (needs[i] > 0 && needs[j] < 0) {
                    --needs[i];
                    ++needs[j];
                    res += j - i;
                    if (needs[j] == 0) ++j;
                }
            }

            while (needs[i] < 0) {
                while (needs[j] <= 0) ++j;
                while (needs[i] < 0 && needs[j] > 0) {
                    ++needs[i];
                    --needs[j];
                    res += j - i;
                    if (needs[j] == 0) ++j;
                }
            }
        }
        return res;
    }
};

/*
装的衣服数为[0, 0, 11, 5]，最终的状态会变为[4, 4, 4, 4]，那么我们将二者做差，
得到[-4, -4, 7, 1]，这里负数表示当前洗衣机还需要的衣服数，正数表示当前洗衣机
多余的衣服数。我们要做的是要将这个差值数组每一项都变为0，对于第一个洗衣机来说，
需要四件衣服可以从第二个洗衣机获得，那么就可以把-4移给二号洗衣机，那么差值数组
变为[0, -8, 7, 1]，此时二号洗衣机需要八件衣服，那么至少需要移动8次。然后二号洗
衣机把这八件衣服从三号洗衣机处获得，那么差值数组变为[0, 0, -1, 1]，此时三号洗衣
机还缺1件，就从四号洗衣机处获得，此时差值数组成功变为了[0, 0, 0, 0]，成功。那么
移动的最大次数就是差值数组中出现的绝对值最大的数字，8次
 */

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % machines.size() != 0) return -1;
        int res = 0, cnt = 0, avg = sum / machines.size();
        for (int m : machines) {
            cnt += m - avg;
            res = max(res, max(abs(cnt), m - avg));
        }
        return res;
    }
};


class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % machines.size() != 0) return -1;
        int n = machines.size(), avg = sum / n;
        vector<int> needs(machines);
        for (int i = 0; i < n; ++i) {
            needs[i] -= avg;
        }
        int res = abs(needs[0]);
        for (int i = 1; i < n; ++i) {
            res = max(needs[i], max(abs(needs[i] + needs[i - 1]), res));
            needs[i] += needs[i - 1];
        }

        return res;
    }
};


// http://blog.csdn.net/tstsugeg/article/details/62427718
// 我觉得这个答案更合理点，上面那个答案没法理解
