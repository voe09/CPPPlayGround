/*
给一个很大的数组，还有一个数组是 blacklist, 要求在大数组中return 不在blacklist 里的数with equal probabity. 只能用O(blacklist)空间
 */

int RandomSelect(vector<int> &nums, vector<int> &blacklist) {
    if (nums.empty()) return -1;
    unordered_set<int> blacklist_set(blacklist.begin(), blacklist.end());
    int cnt = 0;
    int res = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (!blacklist_set.count(nums[i])) {
            ++cnt;
            int tmp = rand() % cnt;
            if (tmp == 0) res = nums[i];
        }
    }
    return res;
}

int main() {
    unordered_map<int, int> m;
    vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> blist {1, 3, 5, 7, 9};
    for (int i = 0; i < 100; ++i) {
        int tmp = RandomSelect(nums, blist);
        ++m[tmp];
    }

    for (const auto &pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
}
