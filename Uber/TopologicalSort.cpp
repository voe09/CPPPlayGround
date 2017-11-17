/*
Given a list of system packages, some packages cannot be installed untill
the other packages are installed. Provide a valid sequence to install all of the
packages.

e.g.
a relies on b
b relies on c
then a valid sequence is [c, b, a]
 */
#include <vector>
#include <unordered_map>
#include <queue>

class Node {
public:
    char val;
    vector<Node*> neighbors;
    int in;
    Node(char x): val(x), in(0) {}
};

vector<char> PackageInstall(vector<char> &packages, 
        vector<pair<char, char>> &dependencies) {
    unordered_map<char, Node*> lookup;
    for (const auto &c: packages) {
        lookup[c] = new Node(c);
    }

    for (const auto &pair : dependencies) {
        lookup[pair.first]->neighbors.push_back(lookup[pair.second]);
        ++(lookup[pair.second]->in);
    }

    queue<Node*> q;
    vector<char> res;
    for (auto &pair : lookup) {
        if (pair.second->in == 0) {
            q.push(pair.second);
        }
    }

    while (!q.empty()) {
        Node *curr = q.front();
        res.push_back(curr->val);
        q.pop();

        for (const auto neighbor : curr->neighbors) {
            --(neighbor->in);
            if (neighbor->in == 0) {
                q.push(neighbor);
            }
        }
    }

    if (res.size() == packages.size()) return res;
    else return {};
}
