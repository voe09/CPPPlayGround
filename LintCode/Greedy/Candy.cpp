/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.

Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

Have you met this question in a real interview? Yes
Example
Given ratings = [1, 2], return 3.

Given ratings = [1, 1, 1], return 3.

Given ratings = [1, 2, 2], return 4. ([1,2,1]).
 */

class Solution {
public:
    /*
     * @param ratings: Children's ratings
     * @return: the minimum candies you must give
     */
    int candy(vector<int> &ratings) {
        // write your code here
        if (ratings.empty()) return 0;
        int n = ratings.size();
        vector<int> candies (n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        int res = accumulate(candies.begin(), candies.end(), 0);
        return res;
    }
};


