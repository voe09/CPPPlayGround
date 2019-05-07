/*
Equations are given in the format A / B = k, where A and B are variables 
represented as strings, and k is a real number (floating point number). 
Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, 
vector<pair<string, string>> queries , where equations.size() == values.size(), 
and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will 
result in no division by zero and there is no contradiction.
 */
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
            vector<double>& values, vector<pair<string, string>> queries) {
        unordered_set<string> nodes;
        map<pair<string, string>, double> weights;
        unordered_map<string, vector<string>> edges;
        int length = equations.size();
        for (int i = 0; i < length; ++i) {
            string &tmp1 = equations[i].first, &tmp2 = equations[i].second;
            nodes.insert(tmp1);
            nodes.insert(tmp2);
            edges[tmp1].push_back(tmp2);
            edges[tmp2].push_back(tmp1);
            weights[equations[i]] = values[i];
            pair<string, string> tmp({tmp2, tmp1});
            weights[tmp] = 1.0 / values[i];
        }
        vector<double> res;
        for (auto& query : queries) {
            DFS(nodes, edges, weights, query.first, query.second, res);
        }
        return res;
    }

private:
    void DFS(unordered_set<string>& nodes,
             unordered_map<string, vector<string>>& edges,
             map<pair<string, string>, double>& weights,
             string& from, string& to, vector<double>& res) {
        if (!nodes.count(from) || !nodes.count(to)) {
            res.push_back(-1.0);
            return;
        }
        unordered_set<string> visited;
        stack<pair<string, double>> stk;
        stk.push({from, 1.0});
        while (!stk.empty()) {
            pair<string, double> cur = stk.top();
            stk.pop();
            if (cur.first == to) {
                res.push_back(cur.second);
                return;
            }
            visited.insert(cur.first);
            for (auto& node : edges[cur.first]) {
                if (!visited.count(node)) {
                    pair<string, string> tmp({cur.first, node});
                    double weight = weights[tmp];
                    stk.push({node, cur.second * weight});
                }
            }
        }
        res.push_back(-1.0);
        return;
    }
};
