/*
You are asked to cut off trees in a forest for a golf event. The forest is 
represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, 
and this positive number represents the tree's height.
You are asked to cut off all the trees in this forest in the order of tree's 
height - always cut off the tree with lowest height first. And after cutting, 
the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you
need to walk to cut off all the trees. If you can't cut off all the trees, 
output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least
one tree needs to be cut off.

Example 1:
Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
Example 2:
Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
Example 3:
Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree 
in (0,0) directly without walking.
Hint: size of the given matrix will not exceed 50x50.
 */

// TLE
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty()) return 0;
        int res = 0;
        int m = forest.size(), n = forest[0].size();
        pq heap;
        BFS(forest, 0, 0, heap);
        while (!heap.empty()) {
            vector<int> tmp = heap.top();
            int x = tmp[0], y = tmp[1], step = tmp[2];
            res += step;
            forest[x][y] = 1;
            while (!heap.empty()) heap.pop();
            BFS(forest, x, y, heap);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) return -1;
            }
        }
        
        return res;
    }

private:
    struct CompPair {
        bool operator() (vector<int>& a, vector<int>& b) {
            return a[3] > b[3];
        }
    };

    typedef priority_queue<vector<int>, vector<vector<int>>, CompPair> pq;

    void BFS(vector<vector<int>>& forest, int x, int y, pq& heap) {
        vector<pair<int, int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<vector<int>> q;
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        q.push({x, y, 0, forest[x][y]});
        visited[x][y] = 1;
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            if (curr[3] > 1) heap.push(curr);
            for (const auto& dir : directions) {
                int i = curr[0] + dir.first, j = curr[1] + dir.second;
                if (i >= 0 && i < m && j >= 0 && j < n && forest[i][j] != 0 && visited[i][j] != 1) {
                    q.push({i, j, curr[2] + 1, forest[i][j]});
                    visited[i][j] = 1;
                }
            }
        }
    }
};

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        // get all the tree positions and sort based on height
        // trees[i][0] is height. The default comparison of vector compare first element before other elements.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        int ans = 0;
        // accumulate all the paths
        for (int i = 0, cur_row = 0, cur_col = 0; i < trees.size(); i++) {
            int step = next_step(forest, cur_row, cur_col, trees[i][1], trees[i][2]);
            // if next tree cannot be reached, step = -1;
            if (step == -1) return -1;
            ans += step;
            cur_row = trees[i][1];
            cur_col = trees[i][2];
        }
        return ans;
    }
private:
    // BFS to find shortest path to next tree; if cannot reach next tree, return -1
    int next_step(vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) return 0;
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> myq;
        myq.push({sr, sc});
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        int step = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!myq.empty()) {
            step++;
            int sz = myq.size();
            for (int i = 0; i < sz; i++) {
                int row = myq.front().first, col = myq.front().second;
                myq.pop();
                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i], c = col + dir[i+1];
                    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
                    if (r == er && c == ec) return step;
                    visited[r][c] = 1;
                    myq.push({r, c});
                }
            }
        }
        return -1;
    }
};
