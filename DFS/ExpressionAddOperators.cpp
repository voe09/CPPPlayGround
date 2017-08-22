/*
Given a string that contains only digits 0-9 and a target value, 
return all possibilities to add binary operators (not unary) +, -, or * between 
the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
 */
/*
用递归来解题，我们需要两个变量diff和curNum，一个用来记录将要变化的值，另一个是
当前运算后的值，而且它们都需要用long long型的，因为字符串转为int型很容易溢出，
所以我们用长整型。对于加和减，diff就是即将要加上的数和即将要减去的数的负值，
而对于乘来说稍有些复杂，此时的diff应该是上一次的变化的diff乘以即将要乘上的数，
有点不好理解，那我们来举个例子，比如2+3*2，即将要运算到乘以2的时候，上次循环的
curNum = 5, diff = 3, 而如果我们要算这个乘2的时候，新的变化值diff应为3*2=6，
而我们要把之前+3操作的结果去掉，再加上新的diff，即(5-3)+6=8，即为新表达式2+3*2的值，
有点难理解，大家自己一步一步推算吧。
special case:
如果输入为"000",0的话, 有0开头的字符串出现，明显这不是数字，所以我们要去掉这些情况，过滤方法也很简单，我们只要判断长度大于1且首字符是‘0’的字符串，将其滤去即可
 */
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        addOperatorsDFS(num, target, 0, 0, "", res);
        return res;
    }

private:
    void addOperatorsDFS(string num, int target, long long diff, long long curNum,
            string out, vector<string>& res) {
        if (num.size() == 0 && curNum == target)
            res.push_back(out);
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if (out.size() > 0) {
                addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
                addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
                addOperatorsDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
            } else {
                addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
            }
        }
    }
};


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        addOperatorsDFS(num, target, 0, 0, "", res);
        return res;
    }
    void addOperatorsDFS(string num, int target, long long diff, long long curNum,
            string out, vector<string> &res) {
        if (num.size() == 0 && curNum == target) {
            res.push_back(out);
        }
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if (out.size() > 0) {
                addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
                addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
                addOperatorsDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
            } else {
                addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
            }
        }
    }
};
