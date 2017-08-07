/*
Given an integer n, generate all structurally unique BST's (binary search trees)
that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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

// DFS
// Wrong answer, 虽然permutation不一样但是binary tree是一样的比如2，1，3和2，3，1
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) return res;
        vector<int> num;
        for (int i = 1; i <= n; ++i) {
            num.push_back(i);
        }
        vector<vector<int>> perm;
        vector<int> curr;
        vector<bool> isVisited(n, false);
        BackTracking(curr, isVisited, perm, num);
        
        for (const auto& p : perm) {
            res.push_back(GenerateTree(p));
        }
        return res;
    }

private:
    void BackTracking(vector<int>& curr, vector<bool>& isVisited,
            vector<vector<int>> &perm, vector<int>& num) {
        if (curr.size() == num.size()) {
            perm.push_back(curr);
            return;
        }

        for (int i = 0; i < isVisited.size(); ++i) {
            if (!isVisited[i]) {
                isVisited[i] = true;
                curr.push_back(num[i]);
                BackTracking(curr, isVisited, perm, num);
                isVisited[i] = false;
                curr.pop_back();
            }
        }
    }

    TreeNode* GenerateTree(const vector<int>& nums) {
        TreeNode* head = new TreeNode(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            TreeNode* curr = head;
            while ((curr->val < nums[i] && curr->right != NULL) ||
                   (curr->val > nums[i] && curr->left != NULL)) {
                if (curr->val < nums[i]) curr = curr->right;
                else if (curr->val > nums[i]) curr = curr->left;
            }

            if (curr->val < nums[i]) curr->right = new TreeNode(nums[i]);
            else if (curr->val > nums[i]) curr->left = new TreeNode(nums[i]);
        }
        return head;
    }
};



// Dynamic Programming
// Idea: 对与某点i来说，可能的BST是#左边子树*#右边子树
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);     
    }

private:
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return {NULL}; // 插入null的目的是使left或者right不为空
        }
        
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = left[j];
                    curr->right = right[k];
                    res.push_back(curr);
                }
            }
        }
        return res;
    }
};
