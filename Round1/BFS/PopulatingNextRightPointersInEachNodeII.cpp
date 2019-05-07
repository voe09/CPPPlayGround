/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next
right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 */

/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/*
递推：在第i层的所有next pointer都连接好的情况下，如何连接第i+1层的next pointer?
显然从第i层的最左节点开始依次通过next pointer遍历这一层，同时将他们的children，
即第i+1层的节点依次通过next pointer连接起来。连接的时候要分情况处理。
http://www.cnblogs.com/grandyang/p/4290148.html
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root && !root->left && !root->right)
            root = root->next;
        if(!root) return;
        TreeLinkNode *leftMost = root->left ? root->left : root->right;
        TreeLinkNode *cur = leftMost;

        while(root) {
            if(cur==root->left) {
                if(root->right) {
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            else if(cur==root->right) {
                root = root->next;
            }
            else {  // cur is the child of the previous node of root
                if(!root->left && !root->right) {
                    root = root->next;
                    continue;
                }
                cur->next = root->left ? root->left : root->right;
                cur = cur->next;
            }
        }
        connect(leftMost);
    }
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *leftMost = root;
        while (leftMost) {
            TreeLinkNode *p = leftMost;
            while (p && !p->left && !p->right) p = p->next;
            if (!p) return;
            leftMost = p->left ? p->left : p->right;
            TreeLinkNode *cur = leftMost;
            while (p) {
                if (cur == p->left) {
                    if (p->right) {
                        cur->next = p->right;
                        cur = cur->next;
                    }
                    p = p->next;
                }
                else if (cur == p->right) {
                    p = p->next;
                } else {
                    if (!p->left && !p->right) {
                        p = p->next;
                        continue;
                    }
                    cur->next = p->left ? p->left : p->right;
                    cur = cur->next;
                }
            }
        }
    }
};
