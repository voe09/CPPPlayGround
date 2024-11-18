class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }

        double res = 0;
        double curr = 1;
        unordered_set<int> visited;
        visited.insert(start_node);
        helper(graph, visited, curr, res, start_node, end_node);
        return res;
    }

    void helper(unordered_map<int, vector<pair<int, double>>>& graph, unordered_set<int>& visited, double& curr, double& res, int s, int target) {
        if (s == target) {
            res = max(res, curr);
            return;
        }

        for (pair<int, double>& child : graph[s]) {
            if (visited.count(child.first)) continue;
            visited.insert(child.first);
            curr *= child.second;
            helper(graph, visited, curr, res, child.first, target);
            curr /= child.second;
            visited.erase(child.first);
        }
    }
};


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }

        priority_queue<pair<int, double>, vector<pair<int, double>>, comp> q;
        vector<double> maxProb(n, 0);
        maxProb[start_node] = 1;
        q.push(make_pair(start_node, 1));
        while (!q.empty()) {
            pair<int, double> t = q.top();
            q.pop();
            if (t.first == end_node) return t.second;
            for (pair<int, double>& child : graph[t.first]) {
                double prob = t.second * child.second;
                if (maxProb[child.first] > prob) continue;
                maxProb[child.first] = prob;
                q.push(make_pair(child.first, prob));
            }
        }
        return 0.0;
    }

private:
    struct comp {
        bool operator()(pair<int, double>& a, pair<int, double>& b) {
            return a.second < b.second;
        }
    };
};
