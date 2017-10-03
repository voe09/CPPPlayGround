/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution
still work?

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
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<pair<TreeLinkNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            pair<TreeLinkNode*, int> curr = q.front();
            q.pop();
            if (!q.empty()) {
                pair<TreeLinkNode*, int> next = q.front();
                if (curr.second == next.second) {
                    curr.first->next = next.first;
                }
            }
            if (curr.first->left) q.push({curr.first->left, curr.second + 1});
            if (curr.first->right) q.push({curr.first->right, curr.second + 1});
        }
    }
};


// Non-recursion, constant space
/*
首先定义了一个leftMost的变量，用来指向每一层最左边的一个节点，由于左子结点可能
缺失，所以这个最左边的节点有可能是上一层某个节点的右子结点，我们每往下推一层时，
还要有个指针指向上一层的父节点，因为由于右子节点的可能缺失，所以上一层的父节点
必须向右移，直到移到有子节点的父节点为止，然后把next指针连上，然后当前层的指针
cur继续向右偏移，直到连完当前层所有的子节点，再向下一层推进，以此类推可以连上
所有的next指针
 */
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
