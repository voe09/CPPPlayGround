/*
Given a string containing only three types of characters: '(', ')' and '*', 
write a function to check whether this string is valid. We define the validity
of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
 */

// DFS: TLE
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> stk;
        return checkParenthesis(s, 0, stk);
    }

private:
    bool checkParenthesis(string s, int start, stack<char> stk) {
        int i = start;
        while (i < s.size() && s[i] != '*') {
            if (s[i] == '(') stk.push('(');
            else {
                if (stk.empty()) return false;
                stk.pop();
            }
            ++i;
        }

        if (i == s.size()) {
            if (stk.empty()) return true;
            else return false;
        }
        else {
            // as '('
            stk.push('(');
            if (checkParenthesis(s, i + 1, stk)) return true;
            stk.pop();

            // as '('
            if (!stk.empty()) {
                stk.pop();
                if (checkParenthesis(s, i + 1, stk)) return true;
                stk.push('(');
            }

            // as empty
            if (checkParenthesis(s, i + 1, stk)) return true;
        }

        return false;
    }
};

// Greedy
class Solution {
public:
    bool checkValidString(string s) {
        // greedy
        // number of '*' appear between each '('
        int star = 0; 
        stack<int> left;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                ++star;
            } else if (s[i] == '(') {
                left.push(star);
                star = 0;
            } else if (s[i] == ')') {
                if (!left.empty()) {
                    star += left.top();
                    left.pop();
                } else if (star > 0) {
                    --star;
                } else {
                    return false;
                }
            }
        }
        // check if still '(' left
        while (!left.empty() && star > 0) {
            star += left.top() - 1;
            left.pop();            
        }
        return left.empty() && star >= 0;
    }
};


/*
Since * can be used as 3 kinds of char, if we do backtrack the complexity can 
blow up if the string is *****.... We need to find a non-trivial method.
Without *, we can just use a number to indicate the unmatch (, ( will increment
it and ) will decrement it. We don't want this number less than 0 all the time 
and it should be 0 when all the string has been matched.
When * is introduced, the number becomes a range, indicating the number of 
possible unmatched ( found. One * just expand the range by 1. And we can use 
the same principle to check if the criteria above is within the range.
 */

class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0, upper = 0;
        for (char c : s) {
            if (c=='(') {
                lower++;
                upper++;
            } else if (c==')') {
                lower--;
                upper--;
            } else { // * encountered
                lower--;
                upper++;
            }
            lower = max(lower, 0);
            if (upper<0) // unmatched ')' found in the middle of string
                return false;
        }
        return lower==0;
    }
};

class Solution {
public:
bool checkValidString(string s) {
    if(s.empty()) return true;
    stack<pair<char, int> > st;
    stack<pair<char, int> > st2;
    int i = 0;
    for(;i < s.size(); ++i){
        if(s[i] == '*'){
            st2.push({s[i],i});
        }else if(s[i] == '('){
            st.push({s[i],i});
        }else{
            if(!st.empty()){
                st.pop();
            }else if(!st2.empty()){
                st2.pop();
            }else{
                break;
            }
        }
    }
    while(!st.empty() && !st2.empty()){
        auto left = st.top();
        auto star = st2.top();
        if(left.second >= star.second){
            break;
        }
        st.pop();
        st2.pop();
    }
    return st.empty() && i == s.size();
}
};


class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), nl = 0/*number of left parenthesis*/, nr = 0/*number of right parenthesis*/;
        for (int i = 0; i < n; ++i) {
            //scan from left to right
            if (s[i] == '(' || s[i] == '*') ++nl;//treat all the '*' as '('
            if (s[i] == ')') {
                if (nl == 0) {//if no left parenthesis can pair this incoming right parenthesis, return false
                    return false;
                } else {
                    --nl;
                }
            }
            //scan from right to left
            if (s[n - i - 1] == ')' || s[n - i - 1] == '*') ++nr;//treat all the '*' as ')'
            if (s[n - i - 1] == '(') {
                if (nr == 0) {//if no right parenthesis can pair this incoming left parenthesis, return false
                    return false;
                } else {
                    --nr;
                }
            }
        }
        return true;//when both direction were passed
    }
};
