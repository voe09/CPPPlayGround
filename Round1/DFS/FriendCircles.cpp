/*
There are N students in a class. Some of them are friends, while some are not. 
Their friendship is transitive in nature. For example, if A is a direct friend
of B, and B is a direct friend of C, then A is an indirect friend of C. 
And we defined a friend circle is a group of students who are direct or indirect
friends.

Given a N*N matrix M representing the friend relationship between students in 
the class. If M[i][j] = 1, then the ith and jth students are direct friends with
each other, otherwise not. And you have to output the total number of friend 
circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
 */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int m = M.size(), n = M[0].size();
        int cnt = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    ++cnt;
                    helper(M, i, j);
                }
            }
        }
        return cnt;
    }

private:
    void helper(vector<vector<int>>& M, int i, int j) {
        M[i][j] = 2;
        int m = M.size(), n = M[0].size();
        vector<pair<int, int>> directions {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (const auto& dir : directions) {
            int x = i + dir.first, y = j + dir.second;
            if (x >= 0 && x < m && y >= 0 && y < n && M[x][y] == 1) {
                helper(M, x, y);
            }
        }
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        int res = 0;
        vector<int> visited (n, 0);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                ++res;
                visited[i] = 1;
                helper(M, visited, i);
            }
        }
        return res;
    }

private:
    void helper(vector<vector<int>>& M, vector<int>& visited, int start) {
        // if (visited[start] == 1) return;

        for (int i = 0; i < M.size(); ++i) {
            if (M[start][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                helper(M, visited, i);
            }
        }
    }
};
