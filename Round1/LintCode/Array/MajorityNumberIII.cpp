/*
Given an array of integers and a number k, the majority number is 
the number that occurs more than 1/k of the size of the array.

Find it.

 Notice

There is only one majority number in the array.

Have you met this question in a real interview? Yes
Example
Given [3,1,2,3,2,3,3,4,4,4] and k=3, return 3.

Challenge 
O(n) time and O(k) extra space
 */

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    int majorityNumber(vector<int> &nums, int k) {
        // write your code here
        unordered_map<int, int> m;
        if (k <= 0 || nums.size() < k) return 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i])) {
                ++m[nums[i]];
            } else if (m.size() < k) {
                m[nums[i]] = 1;
            } else {
                vector<int> delete_items;
                for (auto &pair : m) {
                    --pair.second;
                    if (pair.second == 0) 
                        delete_items.push_back(pair.first);
                }

                for (const auto &item : delete_items) {
                    m.erase(item);
                }
            }
        }

        int majority = 0;
        int max_freq = 0;
        for (const auto &pair : m) {
            if (pair.second > max_freq) {
                majority = pair.first;
                max_freq = pair.second;
            }
        }
        return majority;
    }
};


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> num_cnt;
        if (k <= 0 || nums.size() < k) return 0;
        num_cnt[nums[0]] = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (num_cnt.find(nums[i]) != num_cnt.end()) {
                num_cnt[nums[i]] += 1;
            } else if (num_cnt.size() < k) {
                num_cnt[nums[i]] = 1;
            } else {
                for (auto it = num_cnt.begin(); it != num_cnt.end(); ) {
                    it->second -= 1;
                    if (it->second == 0) {
                        it = num_cnt.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }

        int max_cnt = 0;
        int majority = 0;

        for (auto kv : num_cnt) {
            if (kv.second > max_cnt) {
                max_cnt = kv.second;
                majority = kv.first;
            }
        }
        return majority;
    }
};
