/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the 
minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
 */

// 理解错题意了
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> hours;
        vector<int> minutes;

        for (const auto& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            hours.push_back(hour);
            minutes.push_back(minute);
        }
        int n = timePoints.size();
        int res = INT_MAX;
        vector<vector<int>> diff(n, vector<int>(n, 0));
        for (int i = 1; i < n; ++i) {
            int tmp = (hours[i] > hours[i - 1]) ? (hours[i] - hours[i - 1]) * 60 : (hours[i] + 24 - hours[i - 1]) * 60;
            tmp += (minutes[i] - minutes[i - 1]);
            diff[i][i - 1] = tmp;
            res = min(res, abs(diff[i][i - 1]));
        }

        for (int k = 2; k <= n - 1; ++k) {
            for (int i = 0; i < n - k; ++i) {
                diff[i + k][i] = diff[i + k - 1][i] + diff[i + k][i + 1];
                res = min(res, abs(diff[i + k][i]));
            }
        }
        return res;
    }
};


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX, n = timePoints.size();
        vector<int> nums;
        for (string str : timePoints) {
            int h = stoi(str.substr(0, 2)), m = stoi(str.substr(3));
            nums.push_back(h * 60 + m);
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i) {
            res = min(res, nums[i] - nums[i - 1]);
        }
        return min(res, 1440 + nums[0] - nums.back());
    }
};

/*
 * O(n)
 */

由于时间点并不是无穷多个，而是只有1440个，所以我们建立一个大小为1440的数组来标记某个时间点是否出现过，如果之前已经出现过，说明有两个相同的时间点，直接返回0即可；若没有，将当前时间点标记为出现过。我们还需要一些辅助变量，pre表示之前遍历到的时间点，first表示按顺序排的第一个时间点，last表示按顺序排的最后一个时间点，然后我们再遍历这个mask数组，如果当前时间点出现过，再看如果first不为初始值的话，说明pre已经被更新过了，我们用当前时间点减去pre来更新结果res，然后再分别更新first，last，和pre即可

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX, pre = 0, first = INT_MAX, last = INT_MIN;
        vector<int> mask(1440, 0);
        for (string str : timePoints) {
            int h = stoi(str.substr(0, 2)), m = stoi(str.substr(3));
            if (mask[h * 60 + m] == 1) return 0;
            mask[h * 60 + m] = 1;
        }
        for (int i = 0; i < 1440; ++i) {
            if (mask[i] == 1) {
                if (first != INT_MAX) {
                    res = min(res, i - pre);
                }
                first = min(first, i);
                last = max(last, i);
                pre = i;
            }
        }
        return min(res, 1440 + first - last);
    }
};
