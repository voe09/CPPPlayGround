/*
Clone an undirected graph. Each node in the graph contains a label 
and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and 
each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts 
as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming 
a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/*
和Copy List with Random Pointer那题的思路一样。用一个hash table记录原图节点和
复制图节点间的对应关系，以防止重复建立节点。和那题的不同在于遍历原图相对比
linked list的情况复杂一点
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        UndirectedGraphNode *p1 = node;
        UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        map[p1] = p2;
        queue<UndirectedGraphNode*> q;
        q.push(node);

        while (!q.empty()) {
            p1 = q.front();
            q.pop();
            p2 = map[p1];
            for (int i = 0; i < p1->neighbors.size(); ++i) {
                UndirectedGraphNode *tmp = p1->neighbors[i];
                if (map.count(tmp)) {
                    p2->neighbors.push_back(map[tmp]);
                } else {
                    UndirectedGraphNode *new_tmp = new UndirectedGraphNode(tmp->label);
                    p2->neighbors.push_back(new_tmp);
                    map[tmp] = new_tmp;
                    q.push(tmp);
                }
            }
        }
        return map[node];
    }
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        UndirectedGraphNode *p1 = node;
        UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> ht;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        ht[node] = p2;

        while(!q.empty()) {
            p1 = q.front();
            p2 = ht[p1];
            q.pop();
            for(int i=0; i<p1->neighbors.size(); i++) {
                UndirectedGraphNode *nb = p1->neighbors[i];
                if(ht.count(nb)) {
                    p2->neighbors.push_back(ht[nb]);
                }
                else {
                    UndirectedGraphNode *temp = new UndirectedGraphNode(nb->label);
                    p2->neighbors.push_back(temp);
                    ht[nb] = temp;
                    q.push(nb);
                }
            }
        }

        return ht[node];
    }
};
