/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head) return nullptr;
        ListNode *first = head;
        ListNode *second = head->next;
        while (second) {
            int g = gcd(first->val, second->val);
            first->next = new ListNode(g);
            first->next->next = second;
            first = second;
            second = second->next;
            cout << first->val << endl;
        }
        return head;
    }

    int gcd(int a, int b) {
        if (a < b) return gcd(b, a);
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};