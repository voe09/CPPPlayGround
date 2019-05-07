/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class CompListNode {
public:
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

ListNode* MergeKSortedLists(vector<ListNode*> lists) {
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    priority_queue<ListNode*, vector<ListNode*>, CompListNode> q;
    for (const auto & list : lists) {
        if (list) {
            q.push(list);
        }
    }

    while (!q.empty()) {
        ListNode *tmp = q.top();
        q.pop();
        curr->next = tmp;
        curr = curr->next;
        if (tmp->next) {
            q.push(tmp->next);
        }
    }

    return dummy->next;
}


/*
follow up，如果数据太大了放不下怎么办？答曰：输入输出都放文件，内存就放一个priority queue. 涓€浜�-涓夊垎-鍦帮紝鐙鍙戝竷
follow up 2：万一大到连priority queue也放不下怎么办？答曰：那就得用多个queue，两两merge，然后问了复杂度。
follow up 3：如果再得提高速度怎么办。答曰：因为两两merge时不会相互影响，可以并行着处理。
 */

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct Comp {
	bool operator() (ListNode *a, ListNode *b) {
		return a->val > b->val;
	}
};

ListNode* MergeLists(vector<ListNode*> &lists) {
	priority_queue<ListNode*, vector<ListNode*>, Comp> q;
	ListNode *dummy = new ListNode(0);
	ListNode *curr = dummy;
	for (const auto &list : lists) {
		if (list) {
			q.push(list);
		}
	}

	while (!q.empty()) {
		ListNode *tmp = q.top();
		q.pop();
		curr->next = tmp;
		curr = curr->next;
		if (tmp->next) {
			q.push(tmp->next);
		}
	}

	return dummy->next;
}

int main() {
	vector<ListNode*> lists;
	ListNode *a = new ListNode(0);
	a->next = new ListNode(2);
	a->next->next = new ListNode (10);
	lists.push_back(a);
	ListNode *b = new ListNode(1);
	b->next = new ListNode(5);
	lists.push_back(b);
	ListNode *c = new ListNode(4);
	c->next = new ListNode(12);
	lists.push_back(c);
	auto tmp = MergeLists(lists);
	while (tmp) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
