class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for (string &tp : timePoints) {
            mins.push_back(helper(tp));
        }
        sort(mins.begin(), mins.end());
        int res = INT_MAX, n = mins.size();
        for (int i = 1; i < n; i++) {
            res = min(res, mins[i] - mins[i-1]);
        }

        return min(res, mins[0] - mins[n-1] + 24 * 60);
    }

private:
    int helper(string &t) {
        int res = 0;
        istringstream is(t);
        string token;
        getline(is, token, ':');
        res += stoi(token) * 60;
        getline(is, token, ':');
        res += stoi(token);
        return res;
    }
};