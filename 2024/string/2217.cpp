class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int prefixLength = (intLength + 1) / 2;
        long long mx = pow(10, prefixLength) - pow(10, prefixLength-1);
        long long start = pow(10, prefixLength - 1);
        vector<long long> res;
        for (int q : queries) {
            if (q > mx) {
                res.push_back(-1);
                continue;
            }
            
            string prefix = to_string(start + q - 1);
            string postfix = prefix.substr(0, intLength / 2);
            reverse(postfix.begin(), postfix.end());
            res.push_back(stoll(prefix + postfix));
        }

        return res;
    }
};