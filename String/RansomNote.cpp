/*
Given an arbitrary ransom note string and another string containing letters 
from all the magazines, write a function that will return true 
if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counts(26, 0);
        for (auto& character: ransomNote) {
            counts[character - 'a'] -= 1;
        }

        for (auto& character: magazine) {
            if (counts[character - 'a'] < 0) counts[character - 'a'] += 1;
        }

        int sum = 0;
        for (auto& num: counts) {
            sum += num;
        }
        if (sum == 0) return true;
        return false;
    }
};
