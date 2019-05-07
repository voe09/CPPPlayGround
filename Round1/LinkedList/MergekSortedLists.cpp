/*
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int end = lists.size() - 1;
        while(end > 0) {
            int begin = 0;
            while(begin<end) {
                lists[begin] = merge2Lists(lists[begin], lists[end]);
                begin++;
                end--;
            }
        }
        return lists[0];
    }

private:
    ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *currentNode = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                currentNode->next = l1;
                l1 = l1->next;
                currentNode = currentNode->next;
            } else {
                currentNode->next = l2;
                l2 = l2->next;
                currentNode = currentNode->next;
            }
        }
        currentNode->next = l1 ? l1 : l2; 
        return dummy.next;
    }
};
