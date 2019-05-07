/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(dummy->next);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};


