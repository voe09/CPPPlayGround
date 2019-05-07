/*
A gene string can be represented by an 8-character long string,
with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), 
where ONE mutation is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. 
A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the 
minimum number of mutations needed to mutate from "start" to "end". If there is
no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
 */

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bk;
        unordered_set<string> visited;
        for (const auto& gene : bank) {
            bk.insert(gene);
        }
        if (!bk.count(end)) return -1;
        queue<pair<string, int>> q;
        q.push({start, 0});
        vector<char> choices{'A', 'C', 'G', 'T'};
        while (!q.empty()) {
            pair<string, int> tmp = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 4; ++j) {
                    string new_gene = tmp.first;
                    new_gene[i] = choices[j];
                    if (new_gene == end) return tmp.second + 1;
                    if (bk.count(new_gene) && !visited.count(new_gene)) {
                        q.push({new_gene, tmp.second + 1});
                        visited.insert(new_gene);
                    }
                }
            }
        }
        return -1;
    }
};
