class Solution {
public:
    string nearestPalindromic(string n) {
        long num = stol(n);
        int len = n.size();
        unordered_set<long> candidate;
        candidate.insert(pow(10, len) - 1);
        candidate.insert(pow(10, len-1) - 1);

        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; i++) {
            string pre = to_string(prefix + i);
            string post = pre.substr(0, len/2);
            reverse(post.begin(), post.end());
            long cand = stol(pre + post);
            candidate.insert(cand);
        }
        candidate.erase(num);
        long res = 0, dist = LONG_MAX;
        for (long cand : candidate) {
            if (abs(cand - num) < dist) {
                res = cand;
                dist = abs(cand - num);
            } else if (abs(cand - num) == dist) {
                res = min(res, cand);
            }
        }

        return to_string(res);
    }
};