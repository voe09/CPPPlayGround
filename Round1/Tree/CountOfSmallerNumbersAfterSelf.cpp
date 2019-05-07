/*
You are given an integer array nums and you have to return a new counts array.
The counts array has the property where counts[i] is the number of 
smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

// Binary Search
// 将原数组从右往左插入一个新数组中，插入时的坐标就是其右边较小数字的个数
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (t[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};

// Binary Search Tree
class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
    };
    int insert(Node *&root, int v) {
        if (!root) return (root = new Node(v, 0)), 0;
        if (root->val > v) return root->smaller++, insert(root->left, v);
        else return insert(root->right, v) + root->smaller + (root->val < v ? 1 : 0);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};

// My own binary search tree
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        TreeNode *dummy = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(dummy, nums[i]);
        }
        return res;
    }

private:
    struct TreeNode {
        int val, smaller;
        TreeNode *left, *right;
        TreeNode(int x): val(x), smaller(0), left(NULL), right(NULL) {}
    };

    int insert(TreeNode *&node, int v) {
        if (!node) {
            node = new TreeNode(v);
            return 0;
        } 
        if (node->val < v) {
            return 1 + node->smaller + insert(node->right, v);
        } else {
            node->smaller += 1;
            return insert(node->left, v);
        }
    }
};
