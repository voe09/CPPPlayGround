/*
Remember the story of Little Match Girl? By now, you know exactly what 
matchsticks the little match girl has, please find out a way you can make 
one square by using up all those matchsticks. You should not break any stick, 
but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their 
stick length. Your output will either be true or false, to represent whether 
you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came 
two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
*/

/*
所以首先要做的就是算一下所有火柴的长度和除以4能不能除尽，不能除尽当然不行了。然后排了个序
接着我们就要计算有没有合适的火柴组合可以组合成正方形的单边，这个时候要用到递归了。
前面我们已经做了排序，递归过程中只要发现了当前的长度和大于单边长度就没有必要再继续遍历下去了。
因为满足组合成正方形单边的组合很多，所以每一次遍历都要把所有组合记录下来，
然后在每个组合的基础上再从剩下的火柴中找满足需求的组合。
 */
/*
This question is talking about split the array into 4 groups, they equal to each other.

-- sum the array and divide by 4, calculate the length of edge.
-- using dfs solution, to divide each number into 4 group, to check true or false.
-- when divide, check whether each group sum larger than edge.
*/

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0 || sum == 0) return false;
        std::sort(nums.begin(), nums.end());    // (1)
        vector<int> sums = {0, 0, 0, 0};
        return dfs(nums, 0, sum / 4, sums);
    }
private:
    bool dfs(const vector<int> &nums, int idx, const int &edge, vector<int> &sums) {
        if (idx == nums.size() && sums[0] == sums[1] && sums[1] == sums[2]
            && sums[2] == sums[3]) return true;
        if (idx == nums.size()) return false;
        for (int i = 0; i < 4; ++i) {
            if (sums[i] + nums[idx] <= edge) {  // (2)
                int j = i;
                while (--j >= 0) {
                    if (sums[i] == sums[j]) break; // (3)
                }
                if (j != -1) continue;
                sums[i] += nums[idx];
                if (dfs(nums, idx + 1, edge, sums)) return true;
                sums[i] -= nums[idx];
            }
        }
        return false;
    }
};

/*
 第(1)个剪枝策略的含义是先对所有火柴棒的长度从大到小排序，为什么从大到小排序呢，因为我们的dfs过程中的for循环总是首先尝试把每根火柴棒放到第一个组份中，如果本身无解，则从小到大的策略会慢慢累积和，直到最后加上很长的火柴棒才会发现不满足if语句无解；而如果从大到小排序的话，一开始的累加和就很大，如果无解，则很快能发现不满足if。
 第(2)个剪枝策略的含义是只有当把这根火柴棒加到这个组份中不会超过预定的edge，才把它加入，然后递归。这个很显然的。
 第(3)个剪枝策略参考讨论区，如果递归的时候发现某一个组份当前的和等于之前某个组份的和,
 因为之前那个组份已经递归过了，所以本质上这次递归会和上次递归一样，可以continue掉。
 */
