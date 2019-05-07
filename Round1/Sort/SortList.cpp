/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
O(nlgn)的排序算法没几个，无非就是quick sort， heap sort和merge sort.
对于链表，很明显没有下标这个东西可以用，如果需要定位到第k个元素，只能从节点头部顺序的访问K次
采用merge sort的话，就可以通过递归的特性来避免这个时间损耗
 */

// Recursion method: not constant memory
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        ListNode* end = head;
        while (end->next) {
            end = end->next;
        }
        return sortList(head, end);
    }

    ListNode* sortList(ListNode* begin, ListNode* end) {
        if (begin == end) return begin;
        ListNode* fast = begin;
        ListNode* slow = begin;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        
        ListNode* left = sortList(begin, slow);
        ListNode* right = sortList(fast, end);

        ListNode* dummy = new ListNode(0);
        dummy->next = left;
        ListNode* left_curr = left;
        ListNode* left_prev = dummy;
        ListNode* right_curr = right;
        while (left_curr && right_curr) {
            while (left_curr && left_curr->val < right_curr->val) {
                left_curr = left_curr->next;
                left_prev = left_prev->next;
            }

            ListNode* tmp = right_curr->next;
            left_prev->next = right_curr;
            right_curr->next = left_curr;
            right_curr = tmp;
            left_prev = left_prev->next;
        }
        if (!left_curr) {
            left_prev->next = right_curr;
        }
        return dummy->next;
    }
};


// merge sort iterative http://www.geeksforgeeks.org/iterative-merge-sort/
// Iteration method
1:  ListNode *sortList(ListNode *head) {  
2:       // Get length first  
3:       ListNode* p = head;  
4:       int len = 0;  
5:       while (p != NULL)  
6:       {  
7:            p = p->next;  
8:            len++;  
9:       }  
10:       ListNode* fakehead = new ListNode(-1);  
11:       fakehead->next = head;       
12:       for (int interval = 1; interval <= len; interval = interval * 2)  
13:       {  
14:            ListNode* pre = fakehead;  
15:            ListNode* slow = fakehead->next, *fast = fakehead->next;  
16:            while (fast != NULL || slow != NULL)  
17:            {  
18:                 int i = 0;  
19:                 while (i< interval && fast != NULL)  
20:                 {  
21:                      fast = fast->next; //move fast pointer ahead 'interval' steps  
22:                      i++;  
23:                 }  
24:                 //merge two lists, each has 'interval' length  
25:                 int fvisit = 0, svisit = 0;  
26:                 while (fvisit < interval && svisit<interval && fast != NULL && slow != NULL)  
27:                 {  
28:                      if (fast->val < slow->val)  
29:                      {  
30:                           pre->next = fast;  
31:                           pre = fast;  
32:                           fast = fast->next;  
33:                           fvisit++;  
34:                      }  
35:                      else  
36:                      {  
37:                           pre->next = slow;  
38:                           pre = slow;  
39:                           slow = slow->next;  
40:                           svisit++;  
41:                      }  
42:                 }  
43:                 while (fvisit < interval && fast != NULL)  
44:                 {  
45:                      pre->next = fast;  
46:                      pre = fast;  
47:                      fast = fast->next;  
48:                      fvisit++;  
49:                 }  
50:                 while (svisit < interval && slow != NULL)  
51:                 {  
52:                      pre->next = slow;  
53:                      pre = slow;  
54:                      slow = slow->next;  
55:                      svisit++;  
56:                 }  
57:                 pre->next = fast;  
58:                 slow = fast;  
59:            }  
60:       }  
61:       ListNode* newhead = fakehead->next;  
62:       delete fakehead;  
63:       return newhead;  
64:  }  
