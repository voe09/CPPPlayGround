/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long sum = 0;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *t = q.front();
                sum += static_cast<long long>(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                q.pop();
            }

            pq.push(sum);
            if (pq.size() > k) pq.pop();
        }

        return pq.size() < k ? -1 : pq.top();
    }
};