/*
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode root_node(0);
        ListNode *cur_node = &root_node;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                cur_node->next = l1;
                l1 = l1->next;
                cur_node = cur_node->next;
            } else {
                cur_node->next = l2;
                l2 = l2->next;
                cur_node = cur_node->next;
            }
        }
        
        /*
        while (l1_cur_ptr != NULL) {
            cur_node->next = l1_cur_ptr;
            l1_cur_ptr = l1_cur_ptr->next;
            cur_node = cur_node->next;
        }

        while (l2_cur_ptr != NULL) {
            cur_node->next = l2_cur_ptr;
            l2_cur_ptr = l2_cur_ptr->next;
            cur_node = cur_node->next;
        }
        */
        cur_node->next = l1 ? l1 : l2;

        return root_node.next;
    }
};
