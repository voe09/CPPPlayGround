/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

/*
 * Idea: 先用fast slow两个指针找中点，slow走一步，fast走两步，fast走完，slow在
 * 中点, O(n) space的方法是，slow在走的时候，每次把node的值存入stack里，到中点为止，
 * slow到中点后，继续走，每次check stack.top()再stack.pop();
 *
 * O(1) space的方法是把slow到中点后，把后半段list reverse下，然后比较
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse List btw slow and fast
        ListNode *last = slow->next, *pre = head;
        while (last->next) {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};
