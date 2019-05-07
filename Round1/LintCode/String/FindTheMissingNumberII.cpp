/*
Giving a string with number from 1-n in random order, but miss 1 number.
Find that number.

 Notice

n <= 30

Example
Given n = 20, str = 19201234567891011121314151618

return 17
 */

class Solution {
public:
    /*
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    int findMissing2(int n, string &str) {
        // write your code here
        unordered_map<int, int> m;
        for (int i = 1; i <= n; ++i) {
            if (i < 10) ++m[i];
            else {
                ++m[i / 10];
                ++m[i % 10];
            }
        }

        for (const auto &c : str) {
            int num = c - 'a';
            --m[num];
            if (m[num] == 0) m.erase(num);
        }

        if (m.size() == 1) {
            return m.begin()->first;
        }
        else {
            vector<int> tmp;
            for (const auto &pair : m) {
                tmp.push_back(pair.first);
            }
            sort(tmp.begin(), tmp.end());
            int first = tmp[0], second = tmp[1];
            if (first == 0) 
                return second * 10;
            if (first == 1 && second == 2) {
                if (str.find("12") != string::npos)
                    return 21;
                else
                    return 12;
            }
            return first * 10 + second;
        }
    }
};
