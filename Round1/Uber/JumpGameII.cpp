Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

int numberOfJump(vector<int> &nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> dp (n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (j + nums[j] >= i) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}

// Greedy
int numberOfJump(vector<int> &nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    int begin = 0, curr = 0, end = 0;
    int res = 0;
    while (end < n - 1) {
        int fartest = 0;
        for (int i = begin; i <= end; ++i) {
            if (i + nums[i] > fartest) {
                fartest = i + nums[i];
                curr = i;
            }
        }
        ++res;
        begin = curr + 1;
        end = fartest;
    }
    return res;
}
