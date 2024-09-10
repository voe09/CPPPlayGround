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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int lx = 0, rx = n - 1, uy = 0, dy = m - 1;
        while (head && lx <= rx && uy <= dy) {
            for (int x = lx; head && lx <= rx && x <= rx; x++) {
                res[uy][x] = head->val;
                head = head->next;
            }
            uy++;
            for (int y = uy; head && uy <= dy && y <= dy; y++) {
                res[y][rx] = head->val;
                head = head->next;
            }
            rx--;
            for (int x = rx; head && lx <= rx && x >= lx; x--) {
                res[dy][x] = head->val;
                head = head->next;
            }
            dy--;
            for (int y = dy; head && uy <= dy && y >= uy; y--) {
                res[y][lx] = head->val;
                head = head->next;
            }
            lx++;
        }
        return res;
    }
};