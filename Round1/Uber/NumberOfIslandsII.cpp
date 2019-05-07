/*
Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.
Notice
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.
Example
Given n = 3, m = 3, array of pair A = [(0,0),(0,1),(2,2),(2,1)].
return [1,1,2,2].
 */
pair<int, int> findRoot(vector<vector<int>> &matrix, int x, int y) {
    int m = matrix.size(), n = matrix[0].size();
    while (matrix[x][y] != x * n + y) {
        x = matrix[x][y] / n;
        y = matrix[x][y] % n;
    }
    return {x, y};
}

vector<int> numOfIslands(int m, int n, vector<pair<int, int>> &addIsland) {
    if (addIsland.empty()) return {};
    vector<vector<int>> matrix (m, vector<int>(n, -1));
    vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int cnt = 0;
    vector<int> res;
    for (const auto &add : addIsland) {
        int i = add.first, j = add.second;
        matrix[i][j] = i * n + j;
        ++cnt;
        for (const auto &dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (matrix[x][y] == -1) continue;
                auto root = findRoot(matrix, x, y);
                --cnt;
                matrix[root.first][root.second] = matrix[i][j];
            }
        }
        res.push_back(cnt);
    }
    return res;
}

int main() {
    vector<pair<int, int>> addIsland {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
    auto res = numOfIslands(3, 3, addIsland);
    for (const auto &num : res) {
        cout << num << " ";
    }
    cout << endl;
}
