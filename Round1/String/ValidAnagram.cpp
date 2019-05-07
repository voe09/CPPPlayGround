/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> table;
        for (auto& character: s) {
            table[character] += 1;
        }

        for (auto& character: t) {
            table[character] -= 1;
        }
        
        for (auto& pair: table) {
            if (pair.second != 0) return false;
        }
        return true;
    }
};

// Acutally as only contains lowercase alphabets, cold use vector to simulate hashtable
// the idx is char - 'a';
