/*
给一个list, 每个元素(A, B) 代表A是B的父节点，构建整棵树并输出父节点
随后又问了如果不止一棵树返回多个root，判断是否valid等。
 */

class TreeNode {
public:
    int val;
    int in;
    vector<TreeNode*> neighbors;
    TreeNode(int x) : val(x), in(0) {};
};

vector<TreeNode*> ConstructTree(vector<pair<int, int>> &relations) {

}
