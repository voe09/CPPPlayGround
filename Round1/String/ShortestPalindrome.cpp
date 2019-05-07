/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/



// Wrong Answer

// Below solution would add both in front or at back
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return "";
	if (s.size() == 1) return s;
        int idx = s.size() - 1;
        s.resize(s.size() + s.size() - 1);
        int n = s.size();
        for (int i = s.size() - 1; i >= 0; --i) {
            s[i--] = s[idx--];
            if (i >= 0)
                s[i] = '#';
        }
        
        int shortest = numeric_limits<int>::max();
        int target = 0;
        for (int i = 0; i < s.size(); ++i) {  // if i <= s.size() / 2, it's prob's need
            int left = i, right = i;
            while (left >=0 && right < s.size()) {
                if (s[left] != s[right]) break;
                else {
                    --left;
                    ++right;
                }
            }
            if (!(left >= 0 && right < s.size())) {
                int length = 2 * max(i - 0, n - 1 - i) + 1;
                if (length < shortest) {
                    shortest = length;
                    target = i;
                }
            }
        }
        
        std::cout << s << std::endl;
        std::cout << target << std::endl;
        std::cout << shortest << std::endl;
        
        s.resize(shortest);
        if (target > (n - 1 - target)) {
            int j = 0;
            for (int i = shortest - 1; i >= n; --i) {
                s[i] = s[j++];
            }
        } else if (target < (n - 1 - target)) {
            int j = n - 1;
            int i = shortest - 1;
            while (j >= 0) {
                s[i--] = s[j--];
            }
            int k = 0;
            int t = shortest - 1;
            while (k <= i) {
                s[k++] = s[t--];
            }
        }
        
        int current_idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '#') s[current_idx++] = s[i];
        }
        s.resize(current_idx);
        return s;
    }
};


