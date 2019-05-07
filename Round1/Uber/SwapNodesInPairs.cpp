/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself 
can be changed.
 */


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapNode(ListNode *node) {
    if (!node) return nullptr;
    ListNode *dummy = new ListNode(0);
    dummy->next = node;
    ListNode *p = dummy, *l = node;
    while (l) {
        ListNode *r = l->next;
        if (r) {
            ListNode *n = r->next;
            p->next = r;
            r->next = l;
            l->next = n;
            p = l, l = n;
        }
        else break;
    }
    return dummy->next;
}

int main() {
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);

    auto tmp = swapNode(root);
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
