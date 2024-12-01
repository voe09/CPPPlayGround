class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int num : arr) {
            if (s.count(num * 2)) return true;
            if (num % 2 == 0 && s.count(num/2)) return true;
            s.insert(num);
        }
        return false;
    }
};