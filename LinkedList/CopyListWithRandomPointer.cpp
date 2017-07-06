/*
A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        std::unordered_map<RandomListNode*, RandomListNode*> ht;
        RandomListNode *p1 = head;
        RandomListNode *p2 = new RandomeListNode(head->label);
        ht[head] = p2;
        while (p1) {
            if (p1->next) {
                if (ht.count(p1->next)) {
                    p2->next = ht[p1->next];
                } else {
                    p2->next = new RandomListNode(p1->next->label);
                    ht[p1->next] = p2->next;
                }
            }
            
            if (p1->random) {
                if (ht.count(p1->random)) {
                    p2->random = ht[p1->random];
                } else {
                    p2->random = new RandomListNode(p1->random->label);
                    ht[p1->random] = p2->random;
                }
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return ht[head];
    }
};

// 下面答案会改掉原list，通过不了
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        RandomListNode *currentNode = head;
        RandomListNode *copy = new RandomListNode(currentNode->label);
        while (currentNode) {
            copy->random = currentNode;
            RandomListNode *tmp = currentNode;
            currentNode = currentNode->next;
            tmp->next = copy;
            if (currentNode)
                copy->next = new RandomListNode(currentNode->label);
            copy = copy->next;
        }
        
        currentNode = head->next;
        while (currentNode) {
            if (currentNode->random->random)
                currentNode->random = currentNode->random->random->next;
            else currentNode->random = NULL;
            currentNode = currentNode->next;
        }
        return head->next;
    }
};

/*
1. 遍历原链表，并复制每一个节点，将新节点插入原节点之后

2. 遍历新链表，为其中的新增节点设置random指针

3. 重建原链表，并提取出拷贝的新节点
*/

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Insert the copied node after the original one.
        for (auto *curr = head; curr; curr = curr->next->next) {
            auto *node = new RandomListNode(curr->label);
            node->next = curr->next;
            curr->next = node;
        }

        // Update random node.
        for (auto *curr = head; curr; curr = curr->next->next) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
        }

        // Seperate the copied nodes from original ones.
        RandomListNode dummy(0);
        for (auto *curr = head, *copy_curr = &dummy;
             curr;
             copy_curr = copy_curr->next, curr = curr->next) {
            copy_curr->next = curr->next;
            curr->next = curr->next->next;
        }

        return dummy.next;
    }
};
