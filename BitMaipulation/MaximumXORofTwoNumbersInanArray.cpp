/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

// Idea: a^b = c ->a^c=b,b^c=a 
/*
用一个从左往右的mask，用来提取数字的前缀，然后将其都存入set中，我们用一个变量t，
用来验证当前位为1再或上之前结果res，看结果和set中的前缀异或之后在不在set中，
这里用到了一个性质，若a^b=c，那么a=b^c，因为t是我们要验证的当前最大值，
所以我们遍历set中的数时，和t异或后的结果仍在set中，说明两个前缀可以异或出t的值，
所以我们更新res为t，继续遍历
 */
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;

        for (int i = 31; i >= 0; --i) {
            result <<= 1;
            unordered_set<int> prefixes;
            for (const auto& n : nums) {
                prefixes.emplace(n >> i);
            }
            for (const auto& p : prefixes) {
                if (prefixes.count((result | 1) ^ p)) {
                    ++result;
                    break;
                }
            }
        }

        return result;
    }
};

// Idea: tree
class Solution {
public:
    class TreeNode {
    public:
        TreeNode* next[2];
        TreeNode () {next[0] = NULL; next[1] = NULL;};
    };
    TreeNode* buildTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(), *cur;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            cur = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num >> j) & 1);
                if (cur->next[index] ==  NULL)
                    cur->next[index] = new TreeNode();
                cur = cur->next[index];
            }
        }
        return root;
    }
    
    int helper(TreeNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;
            if (cur->next[index]) {
                res <<= 1;
                res |= 1;
                cur = cur->next[index];
            } else {
                res <<= 1;
                res |= 0;
                cur = cur->next[index ? 0 : 1];
            }
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TreeNode* root = buildTree(nums);
        
        for (auto i : nums) {
            res = max(res, helper(root, i));
        }
        
        return res;
    }
};

