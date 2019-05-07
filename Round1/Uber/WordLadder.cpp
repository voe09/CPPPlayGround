/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
 */

int WordLadder(string start, string end, vector<string> &strs) {
    unordered_set<string> dict (strs.begin(), strs.end());
    unordered_map<string, int> lookup;
    queue<string> q;
    q.push(start);
    dict[start] = 1;
    while (!q.empty()) {
        string curr = q.front();
        if (curr == end) break;
        q.pop();
        for (int i = 0; i < curr.size(); ++i) {
            string tmp = curr;
            for (int j = 0; j < 26; ++j) {
                char c = 'a' + j;
                if (tmp[i] != c) {
                    tmp[i] = c;
                    if (dict.count(tmp) && !lookup.count(tmp)) {
                        lookup[tmp] = lookup[curr] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
    }
    return lookup.count(end) ? lookup[end] : 0;
}
