/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *next, *random;
    TreeNode(int x) : val(x), next(nullptr), random(nullptr) {}
};

TreeNode* deepCopy(TreeNode* root) {
    if (!root) return nullptr;

    TreeNode *curr = root;
    while (curr) {
        TreeNode *later = curr->next;
        curr->next = new TreeNode(curr->val);
        curr->next->next = later;
        curr = later;
    }

    curr = root;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    curr = root;
    TreeNode *dummy = new TreeNode(0);
    TreeNode *ptr = dummy;
    while (curr) {
        ptr->next = curr->next;
        TreeNode *tmp = curr->next->next;
        curr->next = tmp;
        curr = tmp;
        ptr = ptr->next;
    }
    
    return dummy->next;
}

bool isEqual(TreeNode *a, TreeNode *b) {
    if (!a) return !b;
    if (isEqual(a->next, b->next) && isEqual(a->random, b->random)) {
        if (a->val == b->val) return true;
    }
    return false;
}

int main() {
    TreeNode *a = new TreeNode(1);
    a->next = new TreeNode(2);
    a->next->next = new TreeNode(3);
    a->random = a->next->next;
    a->next->random = a->next->next;
    TreeNode *b = deepCopy(a);
    cout << isEqual(a, b) << endl;
}
