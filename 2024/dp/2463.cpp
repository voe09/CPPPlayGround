class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        vector<int> factories;
        for (int i = 0; i < factory.size(); i++) {
            for (int j = 0; j < factory[i][1]; j++) factories.push_back(factory[i][0]);
        }

        int m = robot.size(), n = factories.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i < m; i++) dp[i][n] = 1e12;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                long long assign = static_cast<long long>(abs(robot[i] - factories[j])) + dp[i+1][j+1];
                long long skip = dp[i][j+1];
                dp[i][j] = min(assign, skip);
            }
        }

        return dp[0][0];
    }

};