/*
Clone Graph
*/
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class vertex {
public:
	int val;
	vector<vertex*> neighbors;
	vertex(int x) : val(x) {}
};

vertex* Clone(vertex *node) {
	if (!node) return nullptr;
	queue<vertex*> q;
	q.push(node);
	unordered_map<vertex*, vertex*> m;
	while (!q.empty()) {
		vertex *curr = q.front();
		q.pop();
		if (!m.count(curr)) {
			m[curr] = new vertex(curr->val);
		}
		for (const auto &neighbor : curr->neighbors) {
			if (!m.count(neighbor)) {
				m[neighbor] = new vertex(neighbor->val);
				q.push(neighbor);
			}
			m[curr]->neighbors.push_back(m[neighbor]);
		}
	}
	return m[node];
}

int main() {
	vertex *node1 = new vertex(1);
	vertex *node2 = new vertex(2);
	vertex *node3 = new vertex(3);
	node1->neighbors.push_back(node2);
	node1->neighbors.push_back(node3);
	node2->neighbors.push_back(node2);
	node2->neighbors.push_back(node3);
	node3->neighbors.push_back(node3);
	node3->neighbors.push_back(node2);
	vertex *cp1 = Clone(node1);
	cout << cp1->val << endl;
	cout << endl;
	vertex *cp2 = cp1->neighbors[0];
	cout << cp2->val << endl;
	for (const auto &neighbor : cp2->neighbors) {
		cout << neighbor->val << " ";
	}
	cout << endl;
	cout << endl;
	vertex *cp3 = cp1->neighbors[1];
	cout << cp3->val << endl;
		for (const auto &neighbor : cp3->neighbors) {
		cout << neighbor->val << " ";
	}
	cout << endl;
	

}
