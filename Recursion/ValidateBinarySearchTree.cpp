/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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

// Wrong
/* would say it's true, but it's false
        3
       / \
      2   5
     / \
    1   4
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool leftValid = true, rightValid = true;
        if (root->left) {
            if (root->left->val >= root->val) return false;
            leftValid = isValidBST(root->left);
        }
        if (root->right) {
            if (root->right->val <= root->val) return false;
            rightValid = isValidBST(root->right);
        }

        if (leftValid && rightValid)
            return true;
        else
            return false;

    }
};

// Correct but not efficient
/*
For each node, check if max value in left subtree is smaller than the node and 
min value in right subtree greater than the node
 */

int isBST(struct node* node)
{
  if (node == NULL)
    return(true);

  /* false if the max of the left is > than us */
  if (node->left!=NULL && maxValue(node->left) > node->data)
    return(false);

  /* false if the min of the right is <= than us */
  if (node->right!=NULL && minValue(node->right) < node->data)
    return(false);

  /* false if, recursively, the left or right is not a BST */
  if (!isBST(node->left) || !isBST(node->right))
    return(false);

  /* passing all that, it's a BST */
  return(true);
} 


/*
A better solution looks at each node only once. The trick is to write a utility
helper function isBSTUtil(struct node* node, int min, int max) that traverses 
down the tree keeping track of the narrowing min and max allowed values as it 
goes, looking at each node only once. The initial values for min and max should 
be INT_MIN and INT_MAX — they narrow from there.
 */

// Morris Traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr) {
            if (!curr->left) {
                if (prev && prev->val >= curr->val) {
                    return false;
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    if (prev && prev->val >= curr->val) {
                        return false;
                    }
                    prev = curr;
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return true;
    }
};



class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return valid(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }

    bool valid(TreeNode* node, int minVal, int maxVal) {
        if(!node) {
            return true;
        }

        if(node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return valid(node->left, minVal, node->val) &&
        valid(node->right, node->val, maxVal);
    }
};
