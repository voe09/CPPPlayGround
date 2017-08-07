/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 */

// http://www.cnblogs.com/grandyang/p/6231504.html

class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        priority_queue<pair<int, char>> heap;
        unordered_map<char, int> map;
        for (const auto& c : s) {
            ++map[c];
        }

        for (const auto& pair : map) heap.push({pair.second, pair.first});

        while (!heap.empty()) {
            pair<int, char> p = heap.top();
            heap.pop();
            res.append(p.first, p.second);
        }
        return res;
    }
};
