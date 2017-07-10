/*
One way to serialize a binary tree is to use pre-order traversal. 
When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string 
"9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder 
traversal serialization of a binary tree. 
Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer 
or a character '#' representing null pointer.

You may assume that the input format is always valid, 
for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> stk;
        bool isNum = false;
        int length = preorder.size();
        for (int i = 0; i < length; ++i) {
            string tmp;
            while (i < length && preorder[i] != ',') {
                tmp = tmp + preorder[i++];
            }
            if (tmp != "#") {
                stk.push(tmp);
            } else {
                while (!stk.empty() && stk.top() == "#") {
                    stk.pop();
                    if (stk.empty()) return false;
                    stk.pop();
                }
                stk.push("#");
            }
        }
        return stk.size() == 1 && stk.top() == "#";
    }
};



class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> s;
        stringstream ss(preorder);
        while (!ss.eof()) {
            string val_str;
            getline(ss, val_str, ',');

            if (val_str != "#") {
                s.push(val_str);
            } else {  // val_str == "#"
                while (!s.empty() && s.top() == "#") {
                    s.pop();
                    if (s.empty()) {
                        return false;
                    }
                    s.pop();
                }
                s.push("#");
            }
        }
        return s.size() == 1 && s.top() == "#";
    }
};
