/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to 
first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it 
possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have 
finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have 
finished course 0, and to take course 0 you should also have finished course 1. 
So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, 
not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. 
If a cycle exists, no topological ordering exists and therefore it will be 
impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera 
explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
 */

// http://www.cnblogs.com/grandyang/p/4484571.html

/*
在一个有向图中，每次找到一个没有前驱节点的节点（也就是入度为0的节点）
然后把它指向其他节点的边都去掉，重复这个过程（BFS），直到所有节点已被找到，或者没有符合条件的节点
 */

/*
先修课问题本质上是一个有向图，如果这个图无环，我们可以根据拓扑排序遍历到所有节点，
如果有环则拓扑排序无法完成，遍历到的节点将少于总节点数，因为有的节点是孤岛。
这题我们先根据边的关系，建一个图，并计算每个节点的入度，这里用的是数组来建图。
然后从入度为0的节点，也就是入口开始广度优先搜索，按照拓扑排序的顺序遍历，最后看
遍历过的节点数和总节点数的关系就行了。拓扑排序的使用方法参见外文字典。
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for (const auto& pair : prerequisites) {
            graph[pair.second].push_back(pair.first);
            ++in[pair.first];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (const auto& node : graph[t]) {
                --in[node];
                if (in[node] == 0)
                    q.push(node);
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (in[i] != 0) return false;
        }
        return true;
    }
};
