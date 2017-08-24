/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

// Iterative
class Solution {
public:
bool hasPathSum(TreeNode* root, int sum) {
    //return solution1(root, sum);        //recursive
    return solution2(root, sum);        //iterative
}
private:
bool solution1(TreeNode *n, int sum){
    if(!n) return false;
    if(!n->left && !n->right) return sum - n->val == 0;
    return solution1(n->left, sum - n->val) || solution1(n->right, sum - n->val);
}
bool solution2(TreeNode *n, int sum){
    if(!n) return false;
    stack<TreeNode *> st;
    TreeNode *cur = n, *pre;
    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            sum -= cur->val;
            cur = cur->left;
        }
        cur = st.top();
        if(!cur->left && !cur->right && !sum) return true;
        if(cur->right && pre != cur->right) cur = cur->right;
        else{
            st.pop();
            sum += cur->val;
            pre = cur;
            cur = NULL;
        }
    }
    return false;
}
};
