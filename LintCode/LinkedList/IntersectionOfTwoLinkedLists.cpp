/*
Write a program to find the node at which the intersection of two singly linked lists begins.

 Notice

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Have you met this question in a real interview? Yes
Example
The following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Challenge 
Your code should preferably run in O(n) time and use only O(1) memory.
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
    /*
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        // write your code here
        int lengthA = 0;
        int lengthB = 0;
        ListNode *curr = headA;
        while (curr) {
            ++lengthA;
            curr = curr->next;
        }
        
        curr = headB;
        while (curr) {
            ++lengthB;
            curr = curr->next;
        }

        int step = lengthA - lengthB;
        if (step > 0) {
            while (step > 0) {
                headA = headA->next;
                --step;
            }
        } else {
            while (step < 0) {
                headB = headB->next;
                ++step;
            }
        }

        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        if (headA && headB) return headA;
        else return nullptr;

    }
};
