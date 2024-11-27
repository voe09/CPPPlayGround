// BFS solution, super slow
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < n-1; i++) {
            graph[i][i+1] = 1;
        }

        for (vector<int> &q : queries) {
            graph[q[0]][q[1]] = 1;

            res.push_back(helper(graph, 0, n - 1));
        }

        return res;
    }

    int helper(vector<vector<int>> &graph, int s, int t) {
        queue<int> q;
        vector<bool> visited(graph.size(), false);
        q.push(s);
        visited[s] = true;

        int dist = 0;
        while (!q.empty()) {
            for (int sz = q.size(); sz > 0; sz--) {
                int f = q.front();
                if (f == t) return dist;
                q.pop();
                for (int i = 0; i < graph.size(); i++) {
                    if (graph[f][i] && !visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};


// DP solution
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>> graph(n);
        for (int i = 0; i < n-1; i++) {
            graph[i].push_back(i+1);
        }

        for (vector<int> &q : queries) {
            graph[q[0]].push_back(q[1]);
            res.push_back(helper(graph));
        }

        return res;
    }

    int helper(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int neighbor : graph[i]) {
                dp[i] = min(dp[i], dp[neighbor] + 1);
            }
        }
        return dp[0];
    }
};