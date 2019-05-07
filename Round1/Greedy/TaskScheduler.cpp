/*
Given a char array representing tasks CPU need to do. It contains capital 
letters A to Z where different letters represent different tasks.Tasks could
be done without original order. Each task could be done in one interval. For
each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same
tasks, there must be at least n intervals that CPU are doing different tasks or
just be idle.

You need to return the least number of intervals the CPU will take to finish all
the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts (26, 0);
        for (const auto& task : tasks) {
            ++counts[task - 'A'];
        }
        sort(counts.begin(), counts.end());
        int len = tasks.size(), maxCnt = counts[25], i = 25;
        while (i >= 0 && counts[i] == maxCnt) --i;
        return max(len, (maxCnt - 1) * (n + 1) + 25 - i);
    }
};


/*
先确定好这些高频任务，然后再来安排那些低频任务。如果任务F的出现频率最高，为k次，那么我们用n个空位将每两个F分隔开，然后我们按顺序加入其他低频的任务，来看一个例子：

AAAABBBEEFFGG 3

我们发现任务A出现了4次，频率最高，于是我们在每个A中间加入三个空位，如下：

A---A---A---A

AB--AB--AB--A   (加入B)

ABE-ABE-AB--A   (加入E)

ABEFABE-ABF-A   (加入F，每次尽可能填满或者是均匀填充)

ABEFABEGABFGA   (加入G)

再来看一个例子：

ACCCEEE 2

我们发现任务C和E都出现了三次，那么我们就将CE看作一个整体，在中间加入一个位置即可：

CE-CE-CE

CEACE-CE   (加入A)

注意最后面那个idle不能省略，不然就不满足相同两个任务之间要隔2个时间点了。
 */

/*
想个方法来快速计算出所需时间总长即可。我们仔细观察上面两个例子可以发现，都分成了
(mx - 1)块，再加上最后面的字母，其中mx为最大出现次数。比如例子1中，A出现了4次，
所以有A---模块出现了3次，再加上最后的A，每个模块的长度为4。例子2中，CE-出现了2次，
再加上最后的CE，每个模块长度为3。我们可以发现，模块的次数为任务最大次数减1，
模块出现次数为n+1，最后加上的字母个数为出现次数最多的任务，可能有多个并列。这样
三个部分都搞清楚了，写起来就不难了，我们统计每个大写字母出现的次数，然后排序，
这样出现次数最多的字母就到了末尾，然后我们向前遍历，找出出现次数一样多的任务个数，
就可以迅速求出总时间长了
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            ++cnt[task - 'A'];
        }
        sort(cnt.begin(), cnt.end());
        int i = 25, mx = cnt[25], len = tasks.size();
        while (i >= 0 && cnt[i] == mx) --i;
        return max(len, (mx - 1) * (n + 1) + 25 - i);
    }
};

/*
思路是建立一个优先队列，然后把统计好的个数都存入优先队列中，那么大的次数会在队列
的前面。这题还是要分块，每块能装n+1个任务，装任务是从优先队列中取，每个任务取一个，
装到一个临时数组中，然后遍历取出的任务，对于每个任务，将其哈希表映射的次数减1，
如果减1后，次数仍大于0，则将此任务次数再次排入队列中，遍历完后如果队列不为空，
说明该块全部被填满，则结果加上n+1。我们之前在队列中取任务是用个变量cnt来记录取出
任务的个数，我们想取出n+1个，如果队列中任务数少于n+1个，那就用cnt来记录真实取出
的个数，当队列为空时，就加上cnt的个数
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0, cycle = n + 1;
        unordered_map<char, int> m;
        priority_queue<int> q;
        for (char c : tasks) ++m[c];
        for (auto a : m) q.push(a.second);
        while (!q.empty()) {
            int cnt = 0;
            vector<int> t;
            for (int i = 0; i < cycle; ++i) {
                if (!q.empty()) {
                    t.push_back(q.top()); q.pop();
                    ++cnt;
                }
            }
            for (int d : t) {
                if (--d > 0) q.push(d);
            }
            res += q.empty() ? cnt : cycle;
        }
        return res;
    }
};
