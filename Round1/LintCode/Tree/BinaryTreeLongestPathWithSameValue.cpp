/*
We consider an undirected tree with N nodes, numbered from 1 to N, Additionally, 
each node also has a label attached to it and the label is an integer value. 
Note that different nodes can have identical labels. You need to write a 
function , that , given a zero-indexed array A of length N, where A[J] is the
label value of the (J + 1)-th node in the tree, and a zero-indexed array E of
length K = (N - 1) * 2 in which the edges of the tree are described (for every
0 <= j <= N -2 values E[2 * J] and E[2 * J + 1] represents and edge connecting 
node E[2 * J] with node E[2 * J + 1])， returns the length of the longest path
such that all the nodes on that path have the same label. Then length of a 
path if defined as the number of edges in that path.

 Notice

Assume that: 1 <= N <= 1000

Example
Give A = [1, 1, 1 ,2, 2] and E = [1, 2, 1, 3, 2, 4, 2, 5]
described tree appears as follows:

                   1 （value = 1）
                 /   \
    (value = 1) 2     3 (value = 1)
               /  \
 (value = 2)  4     5 (value = 2)
and your function should return 2, because the longest path (in which all nodes
have the save value of 1) is (2 -> 1 -> 3). The number of edges on this path 
is 2, thus, that is the answer.
 */

class Solution {
public:
    /*
     * @param : as indicated in the description
     * @param : as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
        // write your code here
        int n = A.size();
        vector<vector<int>> tree(n);
        for (int i = 1; i < E.size(); i += 2) {
            tree[E[i] - 1].push_back(E[i - 1] - 1);
            tree[E[i - 1] - 1].push_back(E[i] - 1);
        }

        int res = 0;
        vector<bool> visited (n, false);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            visited[i] = true;
            cnt += helper(A, tree, i, A[i], visited);
            visited[i] = false;
            res = max(res, cnt);
        }
        return res - 1;
    }

private:
    int helper(vector<int> &A, vector<vector<int>> &tree, int root,
            int target, vector<bool> &visited) {
        vector<int> &neighbors = tree[root];
        
        int res = 0;
        for (const auto& neighbor : neighbors) {
            if (!visited[neighbor] && A[neighbor] == target) {
                visited[neighbor] = true;
                res = max(res, helper(A, tree, neighbor, target, visited));
                visited[neighbor] = false;
            }
        }
        return res + 1;
    }
};
