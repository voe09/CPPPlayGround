/*
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Overflow Problem. Wrong answer below
// So could not transfer linked list to number
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_num = 0, l2_num = 0;
        while (l1) {
            l1_num = l1_num * 10 + l1->val;
            l1 = l1->next;
        }

        while (l2) {
            l2_num = l2_num * 10 + l2->val;
            l2 = l2->next;
        }

        int sum = l1_num + l2_num;
        ListNode *tail = new ListNode(sum % 10);
        sum /= 10;
        while (sum) {
            ListNode *tmp = new ListNode(sum % 10);
            sum /= 10;
            tmp->next = tail;
            tail = tmp;
        }

        return tail;
    }
};

// http://www.cnblogs.com/grandyang/p/6216480.html
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getLength(l1), n2 = getLength(l2);
        ListNode *head = new ListNode(1);
        head->next = (n1 > n2) ? helper(l1, l2, n1 - n2) : helper(l2, l1, n2 - n1);
        if (head->next->val > 9) {
            head->next->val %= 10;
            return head;
        }
        return head->next;
    }

private:
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }

    ListNode* helper(ListNode* l1, ListNode* l2, int diff) {
        if (!l1) return NULL;
        ListNode *res = (diff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
        ListNode *post = (diff == 0) ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, diff - 1);
        if (post && post->val > 9) {
            post->val %= 10;
            ++res->val;
        }
        res->next = post;
        return res;
    }
};


// Stack
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<ListNode*> stack1, stack2;
        while (l1) {
            stack1.push(l1);
            l1 = l1->next;
        }

        while (l2) {
            stack2.push(l2);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode *current = NULL;
        while (!stack1.empty() && !stack2.empty()) {
            int num1 = stack1.top()->val, num2 = stack2.top()->val;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            tmp->next = current;
            current = tmp;
            stack1.pop();
            stack2.pop();
        }

        while (!stack1.empty()) {
            int num = stack1.top()->val;
            int sum = num + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            tmp->next = current;
            current = tmp;
            stack1.pop();
        }

        while (!stack2.empty()) {
            int num = stack2.top()->val;
            int sum = num + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            tmp->next = current;
            current = tmp;
            stack2.pop();
        }

        if (carry != 0) {
            ListNode *tmp = new ListNode(carry);
            tmp->next = current;
            current = tmp;
        }

        return current;
    }
};
