class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](vector<int> &a, vector<int> &b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });

        int max_beauty = items[0][1];
        for (int i = 1; i < items.size(); i++) {
            max_beauty = max(items[i][1], max_beauty);
            items[i][1] = max_beauty;
        }

        vector<int> res;
        for (int q : queries) {
            int l = 0, r = items.size();
            // find last items[r-1] whose items[r-1][0] <= q
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (items[mid][0] > q) r = mid;
                else l = mid + 1;
            }
            if (r > 0) res.push_back(items[r-1][1]);
            else res.push_back(0);
        }
        return res;
    }
};