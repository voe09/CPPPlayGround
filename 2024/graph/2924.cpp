class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in(n, 0);
        vector<vector<int>> graph(n);
        for (vector<int> &e : edges) {
            in[e[1]]++;
            graph[e[0]].push_back(e[1]);
        }

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (in[i] != 0) continue;
            visited[i] = true;
            helper(graph, i, visited);
            for (bool v : visited) {
                if (!v) return -1;
            }
            return i;
        }

        return -1;
    }

private:
    void helper(vector<vector<int>> &graph, int i, vector<bool> &visited) {
        for (int j : graph[i]) {
            if (visited[j]) continue;
            visited[j] = true;
            helper(graph, j, visited);
        }
    }
};