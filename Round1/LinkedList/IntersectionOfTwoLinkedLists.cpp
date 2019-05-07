/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/*
找链表交界，很类似Linked List Cycle II那题，方法也是类似的双指针相遇法。分两步走：

1. 如何判断两链表是否相交？
两链表相交则他们必然有共同的尾节点。所以遍历两两链表，找到各自的尾节点，如果tailA!=tailB则一定不相交，反之则相交。

2. 如何判断两链表相交的起始节点？
在第1步判断相交时可以顺带计算两链表的长度lenA和lenB。让长的链表的head先走abs(lenA-lenB)步，然后和短链表的head一起走，直到两者相遇，即为要找的节点。
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lenA = 0, lenB = 0;
        ListNode *tailA = headA, *tailB = headB;
        
        while(tailA->next) {
            tailA = tailA->next;
            lenA++;
        }
        while(tailB->next) {
            tailB = tailB->next;
            lenB++;
        }
        if(tailA!=tailB) return NULL;
        
        if(lenA>lenB) {
            for(int i=0; i<lenA-lenB; i++)
                headA = headA->next;
        }
        else {
            for(int i=0; i<lenB-lenA; i++)
                headB = headB->next;
        }
        
        while(headA!=headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};

/*
我当时的思路，先遍历A, get到tail A，构建一个dummy node，dummy->next = tailA， reverse(headA, tailA); 再遍历B，如果最后一个node是headA，则有相交；如果相交，try to reverse（headB, dummy->next)；如果在某一点会遇到链断开，则该点就是相交的点，此时，从dummy->next出发，走到端点，讲相交点与端点相连，再讲端点和dummy->next reverse一遍，return相交的点；
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        // Reverse one linked list
        ListNode *currentNode = headA;
        while (currentNode->next) {
            currentNode = currentNode->next;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = currentNode;
        ReverseLinkedList(headA, currentNode);
        
        // 从headB开始走，如果最后一个点不是headA，return NULL
        // try to ReverseLinkedList(headB, dummy->next)发现有个点是断开的，存入断开的点
        // 从dummy->next 开始走，一直到最后一个点，first = 断开的点，second = 端点，first->next = second， 然后开始reverse second 到dummy->next;
        // return 存着的断开的点
    }
private:
    void ReverseLinkedList(ListNode *start, ListNode *end) {
        ListNode *first = start;
        ListNode *second = start->next;
        start->next = NULL;
        do {
            ListNode *tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        } while (second != end);
    }
};
