/*
Create a data structure that stores integers, let then add,
delete. It also should be able to return the minimum diff value
of the current integers.
Tha is
min_diff = minimum(|x_i - x_j|)
Example:
-1, 3, 4, 10, 11, 11
min_diff = 0
*/

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x) {}
};

class QueueNode {
public:
    int val;
    TreeNode *first, *second;
    TreeNode(int x, TreeNode *a,
             Treenode *b) : val(x), first(a), second(b) {}
}

class CompNode {
public:
    bool operator() (QueueNode &a, QueueNode &b) {
        return a.val > b.val;
    }
}

class DataStructure {

    
    
private:
    TreeNode *root;
    priority_queue<
};
