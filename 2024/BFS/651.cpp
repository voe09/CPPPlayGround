/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode *root) {
        if (!root) return {};
        unordered_map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        int mn = INT_MAX, mx = INT_MIN;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                pair<int, TreeNode*> t = q.front();
                mn = min(mn, t.first);
                mx = max(mx, t.first);
                q.pop();
                m[t.first].push_back(t.second->val);
                if (t.second->left) q.push({t.first-1, t.second->left});
                if (t.second->right) q.push({t.first+1, t.second->right});
            }
        }

        vector<vector<int>> res;
        for (int i = mn; i <= mx; i++) {
            if (!m.count(i)) continue;
            res.push_back(m[i]);
        }

        return res;
    }
};