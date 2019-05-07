/*
In the video game Fallout 4, the quest "Road to Freedom" requires players to 
reach a metal dial called the "Freedom Trail Ring", and use the dial to spell 
a specific keyword in order to open the door.

Given a string ring, which represents the code engraved on the outer ring and 
another string key, which represents the keyword needs to be spelled. You need 
to find the minimum number of steps in order to spell all the characters in the
keyword.

Initially, the first character of the ring is aligned at 12:00 direction. 
You need to spell all the characters in the string key one by one by rotating
the ring clockwise or anticlockwise to make each character of the string key
aligned at 12:00 direction and then by pressing the center button. 
At the stage of rotating the ring to spell the key character key[i]:
You can rotate the ring clockwise or anticlockwise one place, which counts as
1 step. The final purpose of the rotation is to align one of the string ring's
characters at the 12:00 direction, where this character must equal to the
character key[i].
If the character key[i] has been aligned at the 12:00 direction, you need to
press the center button to spell, which also counts as 1 step. After the
pressing, you could begin to spell the next character in the key (next stage),
otherwise, you've finished all the spelling.
Example:


Input: ring = "godding", key = "gd"
Output: 4
Explanation:
 For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
 For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
 Also, we need 1 more step for spelling.
 So the final output is 4.
Note:
Length of both ring and key will be in range 1 to 100.
There are only lowercase letters in both strings and might be some duplcate characters in both strings.
It's guaranteed that string key could always be spelled by rotating the string ring.
 */

// TLE
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> lookup;
        int length = ring.size();
        for (int i = 0; i < ring.size(); ++i) {
            lookup[ring[i]].push_back(i);
        }
        return findRotateSteps(lookup, length, 0, key, 0);
    }

private:
    int findRotateSteps(unordered_map<char, vector<int>>& ring, int length, 
            int start, string& key, int target) {
        if (target == key.size()) return 0;
        vector<int> tmp = ring[key[target]];
        int tmp_length = tmp.size();
        int left = -1, right = 0;

        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] <= start) {
                ++left;
                ++right;
            } else break;
        }

        left = (left < 0) ? left + tmp_length : left;
        right %= tmp_length;
        
        left = tmp[left];
        right = tmp[right];
        int moveLeft = (start - left < 0) ? start - left + length : start - left;
        int moveRight = (right - start < 0) ? right - start + length : right - start;
        
        if (left == right) return min(moveLeft, moveRight) + 1 + findRotateSteps(ring, length, left, key, target + 1);

        return min(moveLeft + 1 + findRotateSteps(ring, length, left, key, target + 1),
                moveRight + 1 + findRotateSteps(ring, length, right, key, target + 1));
    }
};


/*
其中dp[i][j]表示转动从i位置开始的key串所需要的最少步数(这里不包括spell的步数，因为spell可以在最后统一加上)，此时表盘的12点位置是ring中的第j个字符。不得不佩服这样的设计的确很巧妙，我们可以从key的末尾往前推，这样dp[0][0]就是我们所需要的结果，因为此时是从key的开头开始转动，而且表盘此时的12点位置也是ring的第一个字符。现在我们来看如何找出递推公式，对于dp[i][j]，我们知道此时要将key[i]转动到12点的位置，而此时表盘的12点位置是ring[j]，我们有两种旋转的方式，顺时针和逆时针，我们的目标肯定是要求最小的转动步数，而顺时针和逆时针的转动次数之和刚好为ring的长度n，这样我们求出来一个方向的次数，就可以迅速得到反方向的转动次数。为了将此时表盘上12点位置上的ring[j]转动到key[i]，我们要将表盘转动一整圈，当转到key[i]的位置时，我们计算出转动步数diff，然后计算出反向转动步数，并取二者较小值为整个转动步数step，此时我们更新dp[i][j]，更新对比值为step + dp[i+1][k]，这个也不难理解，因为key的前一个字符key[i+1]的转动情况suppose已经计算好了，那么dp[i+1][k]就是当时表盘12点位置上ring[k]的情况的最短步数，step就是从ring[k]转到ring[j]的步数，也就是key[i]转到ring[j]的步数，用语言来描述就是，从key的i位置开始转动并且此时表盘12点位置为ring[j]的最小步数(dp[i][j])就等价于将ring[k]转动到12点位置的步数(step)加上从key的i+1位置开始转动并且ring[k]已经在表盘12点位置上的最小步数(dp[i+1][k])之和。
 */

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(m + 1, vector<int>(n));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (ring[k] == key[i]) {
                        int diff = abs(j - k);
                        int step = min(diff, n - diff);
                        dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
                    }
                }
            }
        }
        return dp[0][0] + m;
    }
};

/*
也就是用memo数组来保存已经计算过的结果，否则大量的重复运算是无法通过OJ的。其实这里的memo数组也起到了跟上面解法中的dp数组相类似的作用，还有就是要注意数组v的作用，记录了每个字母在ring中的出现位置，由于ring中可能有重复字符，而且麻烦的情况是当前位置向两个方向分别转动相同的步数会分别到达两个相同的字符，这也是贪婪算法会失效的一个重要原因，而且也是上面的解法在找到ring[k] == key[i]并处理完之后不break的原因，因为后面还有可能找到。上面的迭代解法中使用到的变量i和j可以直接访问到，而在递归的写法中必须要把位置变量x和y当作参数导入进去，这样才能更新正确的地方
 */

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> v(26);
        vector<vector<int>> memo(n, vector<int>(m));
        for (int i = 0; i < n; ++i) v[ring[i] - 'a'].push_back(i);
        return helper(ring, key, 0, 0, v, memo);
    }
    int helper(string ring, string key, int x, int y, vector<vector<int>>&v, vector<vector<int>>& memo) {
        if (y == key.size()) return 0;
        if (memo[x][y]) return memo[x][y];
        int res = INT_MAX, n = ring.size();
        for (int k : v[key[y] - 'a']) {
            int diff = abs(x - k);
            int step = min(diff, n - diff);
            res = min(res, step + helper(ring, key, k, y + 1, v, memo));
        }
        return memo[x][y] = res + 1;
    }
};
