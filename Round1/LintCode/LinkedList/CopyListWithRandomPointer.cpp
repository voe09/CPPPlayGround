/*
A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.

Have you met this question in a real interview? Yes
Example
Challenge 
Could you solve it with O(1) space?
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (!head) return nullptr;
        RandomListNode *curr = head;
        RandomListNode *later = curr->next;
        while (curr) {
            RandomListNode *tmp = new RandomListNode(curr->label);
            curr->next = tmp;
            tmp->next = later;
            curr = later;
            if (curr) later = curr->next;
        }

        // copy random pointer
        curr = head;
        later = curr->next;
        while (curr) {
            if (curr->random) {
                later->random = curr->random->next;
            }
            curr = curr->next->next;
            if (curr)
                later = curr->next;
        }

        // decompose the list
        curr = head;
        later = curr->next;
        RandomListNode *root = curr->next;
        while (curr) {
            curr->next = later->next;
            curr = curr->next;
            if (curr) {
                later->next = curr->next;
                later = later->next;
            }
        }
        return root;
    }
};
