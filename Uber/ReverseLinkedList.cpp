/*
Reverse Linked List
 */

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode *root) {
    if (!root || !(root->next)) return root;
    ListNode *dummy = nullptr;
    ListNode *prev = dummy, *curr = root;
    while (curr) {
        ListNode *tmp = curr->next;
        curr->next = prev;
        prev = curr, curr = tmp;
    }
    return prev;
}


