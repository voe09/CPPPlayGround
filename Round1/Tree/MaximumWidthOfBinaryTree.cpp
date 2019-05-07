/*
Given a binary tree, write a function to get the maximum width of the given tree.
The width of a tree is the maximum width among all levels. The binary tree has 
the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes
(the leftmost and right most non-null nodes in the level, where the null nodes 
between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 
(5,3,null,9).
Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// MLE
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int res = 0, cnt = 0, prev = 0, nullNode = 0;
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            if (curr.second == prev) {
                if (!curr.first) ++nullNode;
                else {
                    cnt += nullNode + 1;
                    nullNode = 0;
                }
            } else {
                res = max(res, cnt);
                prev = curr.second;
                while (!q.empty() && !curr.first) {
                    curr = q.front();
                    q.pop();
                }
                if (q.empty() && !curr.first) break;
                cnt = 1;
                nullNode = 0;
            }
            if (curr.first) {
                q.push({curr.first->left, curr.second + 1});
                q.push({curr.first->right, curr.second + 1});
            } else {
                q.push({nullptr, curr.second + 1});
                q.push({nullptr, curr.second + 1});
            }
        }

        res = max(res, cnt);
        return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int leftMost = 1, rightMost = 1, res = 0;
        TreeNode *leftNode = root, *right = root;
        while (left && right) {
            res = max(res, rightMost - leftMost + 1);
            if (left->left
        }
    }
};


// DFS
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts; // left most nodes at each level;
        return dfs(root, 1, 0, lefts);
    }
private:
    int dfs(TreeNode* n, int id, int d, vector<int>& lefts) { // d : depth
        if (!n) return 0;
        if (d >= lefts.size()) lefts.push_back(id);  // add left most node
        return max({id + 1 - lefts[d], dfs(n->left, id * 2, d + 1, lefts), dfs(n->right, id * 2 + 1, d + 1, lefts)});
    }
};


// DFS side effect
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts; // left most nodes at each level;
        int maxwidth = 0;
        dfs(root, 1, 0, lefts, maxwidth);
        return maxwidth;
    }
private:
    void dfs(TreeNode* node, int id, int depth, vector<int>& lefts, int& maxwidth) {
        if (!node) return;
        if (depth >= lefts.size()) lefts.push_back(id);  // add left most node
        maxwidth = max(maxwidth, id + 1 - lefts[depth]);
        dfs(node->left, id * 2, depth + 1, lefts, maxwidth);
        dfs(node->right, id * 2 + 1, depth + 1, lefts, maxwidth);
    }
};

// BFS
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int max = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 1));
        while (!q.empty()) {
            int l = q.front().second, r = l; // right started same as left
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) q.push(pair<TreeNode*, int>(node->left, r * 2));
                if (node->right) q.push(pair<TreeNode*, int>(node->right, r * 2 + 1));
            }
            max = std::max(max, r + 1 - l);
        }
        return max;
    }
};


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int res = 0;
        while (!q.empty()) {
            int l = q.front().second, r = l;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) q.push({node->left, r * 2});
                if (node->right) q.push({node->right, r * 2 + 1});
            }
            res = max(res, r + 1 - l);
        }
        return res;
    }
};
