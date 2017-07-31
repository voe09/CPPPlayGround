/* 
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::multimap<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            hash_map.insert({nums[i], i});
        }
        std::vector<int> result;
        std::sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            if ((nums[start] + nums[end]) > target) {
                --end;
            } else if ((nums[start] + nums[end]) < target) {
                ++start;
            } else {
                int idx_1;
                int idx_2;
                if (nums[start] == nums[end]) {
                    // equal_range is c++ 11 feature
                    auto pair = hash_table.equal_range(nums[start]);
                    idx_1 = pair.first->second;
                    idx_2 = pair.second->second;
                    // if only use c++ 98
                    idx_1 = hash_table.find(nums[start])->second;
                    idx_2 = (++hash_table.find(nums[start]))->second;
                } else {
                    idx_1 = hash_map.find(nums[start])->second;
                    idx_2 = hash_map.find(nums[end])->second;
                }

                if (idx_1 < idx_2) {
                    result.push_back(idx_1);
                    result.push_back(idx_2);
                } else {
                    result.push_back(idx_2);
                    result.push_back(idx_1);
                }

                return result;
            }
        }
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unorderd_map<int, int> hash_map;
        std::vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int complementary_num = target - nums[i];
            if (hash_map.find(complementary_num) != hash_map.end()) {
                result.push_back(hash_map[complementary_num]);
                result.push_back(i);
                return result;
            } else {
                hash_map[nums[i]] = i;
            }
        }
    }
};





