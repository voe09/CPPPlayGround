/*
A frog is crossing a river. The river is divided into x units and at each unit 
there may or may not exist a stone. The frog can jump on a stone, but it must 
not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, 
determine if the frog is able to cross the river by landing on the last stone. 
Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, 
k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
 */


// Wrong answer, don't have to jump to some units
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n <= 1) return true;
        vector<int> gap(n, 0);
        for (int i = 1; i < n; ++i) {
            gap[i] = stones[i] - stones[i - 1];
        }
        if (gap[1] != 1) return false;
        vector<bool> dp(n, false);
        dp[0] = true;
        dp[1] = true;
        for (int i = 2; i < n; ++i) {
            if (gap[i] >= gap[i - 1] - 1 && gap[i] <= gap[i - 1] + 1 && dp[i - 1])
                dp[i] = true;
        }
        return dp[n - 1];
    }
};

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false;
        }

        unordered_map<int, unordered_set<int>> last_jump_units;
        for (const auto& s: stones) {
            last_jump_units.emplace(s, unordered_set<int>());
        }
        last_jump_units[1].emplace(1);

        for (int i = 0; i + 1 < stones.size(); ++i) {
            for (const auto& j : last_jump_units[stones[i]]) {
                for (const auto& k : {j - 1, j, j + 1}) {
                    if (k > 0 && last_jump_units.count(stones[i] + k)) {
                        last_jump_units[stones[i] + k].emplace(k);
                    }
                }
            }
        }

        return !last_jump_units[stones.back()].empty();
    }
};

// TLE
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        vector<int> jump{1};
        unordered_set<int> stone_sets(stones.begin(), stones.end());
        int target = stones.back();
        return DFS(0, jump, stone_sets, target);
    }

    bool DFS(int from, vector<int>& jump, unordered_set<int>& stones, int target) {
        int last_jump = jump.back();
        if (from + last_jump == target) return true;
        from += last_jump;

        for (const auto& current_jump : {last_jump - 1, last_jump, last_jump + 1}) {
            if (current_jump > 0 && stones.count(from + current_jump)) {
                jump.push_back(current_jump);
                if (DFS(from, jump, stones, target)) return true;
                jump.pop_back();
            }
        }
        return false;
    }
};
