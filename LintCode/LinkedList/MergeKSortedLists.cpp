/*
Merge k sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.

Have you met this question in a real interview? Yes
Example
Given lists:

[
  2->4->null,
  null,
  -1->null
],
return -1->2->4->null.
 */

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.empty()) return nullptr;
        int right = lists.size() - 1;
        while (right > 0) {
            int left = 0;
            while (left < right) {
                lists[left] = merge2Lists(lists[left], lists[right]);
                ++left;
                --right;
            }
        }
        return lists[0];
    }

private:
    ListNode *merge2Lists(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
                curr = curr->next;
            }
            else {
                curr->next = right;
                right = right->next;
                curr = curr->next;
            }
        }
        
        curr->next = left ? left : right;

        return dummy->next;
    }

};


class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, comp> heap;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) heap.push(lists[i]);
        }
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (!heap.empty()) {
            ListNode *tmp = heap.top();
            curr->next = tmp;
            curr = curr->next;
            heap.pop();
            tmp = tmp->next;
            if (tmp) heap.push(tmp);
        }
        return dummy->next;
    }

private:
    struct comp {
        bool operator() (ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
};
