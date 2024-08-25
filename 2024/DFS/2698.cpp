class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            string sqStr = to_string(sq);
            if (helper(sqStr, 0, 0, 0, i)) {
                res += sq;
            }
        }
        return res;
    }

    bool helper(string &str, int i, int curr, int sum, int target) {
        if (i >= str.size()) {
            if (curr == 0) return sum == target;
            return false; 
        }

        curr = curr * 10 + (str[i] - '0');
        if (helper(str, i+1, 0, sum+curr, target)) return true;;
        if (helper(str, i+1, curr, sum, target)) return true;
        return false;
    }

};