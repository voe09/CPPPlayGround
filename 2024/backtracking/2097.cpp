// incorrect solution
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> ins(n, 0);
        unordered_set<Node*> nodes;
        unordered_map<int, vector<Node*>> innodes, outnodes;

        for (vector<int> &pair : pairs) {
            int in = pair[0], out = pair[1];
            Node *node = new Node(in, out);

            node->indegree = outnodes[in].size();
            for (Node* p : outnodes[in]) {
                p->childs.push_back(node);
                p->outdegree++;
            }

            node->outdegree = innodes[out].size();
            for (Node* c : innodes[out]) {
                node->childs.push_back(c);
                c->indegree++;
            }

            nodes.insert(node);
            innodes[in].push_back(node);
            outnodes[out].push_back(node);
        }

        Node *root = nullptr;
        for (Node *node : nodes) {
            cout << node->in << ',' << node->out << ':' << node->indegree <<',' << node->outdegree << endl;
            if (node->outdegree == node->indegree + 1) {
                root = node;
                break;
            }
        }

        // a circle
        if (!root) root = *nodes.begin();

        vector<vector<int>> res;
        if (!root) return res;
        vector<vector<int>> curr;
        curr.push_back({root->in, root->out});
        nodes.erase(root);
        helper(root, nodes, curr, res);
        return res;
    }

private:
    struct Node {
        int in;
        int out;
        int indegree;
        int outdegree;
        vector<Node*> childs;

        Node(int i, int o) : in(i), out(o), indegree(0), outdegree(0) {}
    };

    void helper(Node* node, unordered_set<Node*> &nodes, vector<vector<int>> &curr, vector<vector<int>> &res) {
        if (nodes.empty()) {
            res = curr;
            return;
        }

        for (Node *c : node->childs) {
            if (!nodes.count(c)) continue;
            nodes.erase(c);
            curr.push_back({c->in, c->out});
            helper(c, nodes, curr, res);
            nodes.insert(c);
            curr.pop_back();
        }
    }
};