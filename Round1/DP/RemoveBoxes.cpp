/*
Given several boxes with different colors represented by different 
positive numbers. 
You may experience several rounds to remove boxes until there is no box left. 
Each time you can choose some continuous boxes with the same color (composed 
of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.

Example 1:
Input:

[1, 3, 2, 2, 2, 3, 4, 3, 1]
Output:
23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
Note: The number of boxes n would not exceed 100.
 */

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {

    }
};

/*
We use danymic programming to solve this problem.
step 1
First, we merge the blocks with same color to one segment.
for example, if we have 1 2 3 3 2 2 2 1, then we got 1 2 3 2 1. and at the 
same time ,we use c[i] and len[i] to maintain the color and number of blocks
of the i_th segment.
In the previous example, c[] is: 1 2 3 2 1, len[] is 1 1 2 3 1
step 2
danymic programming, and this step is based on step1.
we use d[i, j, k] to show that: in [i, j], we got k blocks with same color of segment j after j.
and we have 2 ways to do next:

merge segment j and the k blocks after j because the have the same color:
d[i, j, k] = d[i, j - 1, 0] + (len[j] + k) * (len[j] + k)
we accumulate segment j and the k blocks to segment pos(pos is before j) if segment j and segment pos has the same color:
if (c[pos] == c[j]): d[i, j, k] = d[i, pos,len[j] + k] + d[pos + 1, j - 1, 0] (i <= pos < j)
time complexity: O(n^4)
code:

const int maxn = 105;
int d[maxn][maxn][maxn];
*/

// http://www.cnblogs.com/grandyang/p/6850657.html
class Solution {
private:
    int c[maxn], len[maxn];
public:
    int dfs(int i, int j, int k) {
        if (d[i][j][k] != -1) return d[i][j][k];
        if (i > j) return 0;
        d[i][j][k] = dfs(i, j - 1, 0) + (len[j] + k) * (len[j] + k);
        for (int pos = i; pos < j; pos++) {
            if (c[pos] == c[j]) d[i][j][k] = max(d[i][j][k], dfs(i, pos, len[j] + k) + dfs(pos + 1, j - 1, 0));
        }
        return d[i][j][k];
    }

    int removeBoxes(vector<int>& boxes) {
        int n = 0;
        memset(c, 0, sizeof(c));
        memset(len, 0, sizeof(len));
        memset(d, -1, sizeof(d));
        for (int i = 0; i < boxes.size(); i++) {
            if (i == 0 || boxes[i] != boxes[i - 1]) c[++n] = boxes[i], len[n] = 1;
            else len[n]++;
        }
        return dfs(1, n, 0);
    }
};
