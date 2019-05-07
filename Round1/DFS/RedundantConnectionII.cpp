/*
In this problem, a rooted tree is a directed graph such that, there is exactly
one node (the root) for which all other nodes are descendants of this node, 
plus every node has exactly one parent, except for the root node which has 
no parents.

The given input is a directed graph that started as a rooted tree with N nodes 
(with distinct values 1, 2, ..., N), with one additional directed edge added. 
The added edge has two different vertices chosen from 1 to N, and was not an
edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a
pair [u, v] that represents a directed edge connecting nodes u and v, where u 
is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree
of N nodes. If there are multiple answers, return the answer that occurs last
in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
 */

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graphs;
        unordered_map<int, int> fathers;
        int root = -1;
        for (const auto& edge : edges) {
            int out = edge[0], in = edge[1];
            if (fathers.count(in)) return edge;
            fathers[in] = out;
            graphs[out].push_back(in);
            if (graphs[out].size() > 1) root = out;
        }
        if (root == -1) return edges.back();
        stack<int> stk;
        unordered_set<int> visited;
        stk.push(root);
        while (!stk.empty()) {
            int curr = stk.top();
            stk.pop();
            visited.insert(curr);
            for (const auto& node : graphs[curr]) {
                if (!visited.count(node)) {
                    stk.push(node);
                } else {
                    return {curr, node};
                }
            }
        }
        return {};
    }
};



1. every tree node (except the root) has only one father
2. no cycle in the tree.
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int u, v;
        for(const auto &e: edges){
            u = e[0]; v = e[1];
            //a node has multiple fathers
            if(fa.find(v) != fa.end() && fa[v] != u) return e;
            fa[v] = u;
            if(hasCycle(v)) return e;
        }
        return {};
    }
    bool hasCycle(int v){
        int node = v;
        while(fa.find(v) != fa.end()){
            v = fa[v];
            if(v == node) return true;
        }
        return false;
    }
    unordered_map<int, int> fa;
};
