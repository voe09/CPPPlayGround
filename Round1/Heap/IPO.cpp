/*
Suppose LeetCode will start its IPO soon. In order to sell a good price of its 
shares to Venture Capital, LeetCode would like to work on some projects to 
increase its capital before the IPO. Since it has limited resources, it can 
only finish at most k distinct projects before the IPO. Help LeetCode design 
the best way to maximize its total capital after finishing at most k distinct projects.

You are given several projects. For each project i, it has a pure profit Pi and
a minimum capital of Ci is needed to start the corresponding project. Initially,
you have W capital. When you finish a project, you will obtain its pure profit
and the profit will be added to your total capital.

To sum up, pick a list of at most k distinct projects from given projects to
maximize your final capital, and output your final maximized capital.

Example 1:
Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].

Output: 4

Explanation: Since your initial capital is 0, you can only start the project indexed 0.
             After finishing it you will obtain profit 1 and your capital becomes 1.
             With capital 1, you can either start the project indexed 1 or the project indexed 2.
             Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
             Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
Note:
You may assume all numbers in the input are non-negative integers.
The length of Profits array and Capital array will not exceed 50,000.
The answer is guaranteed to fit in a 32-bit signed integer.
 */

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<int> res (k + 1, 0);
        res[0] = W;
        priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            ComparePair> heap;
        vector<pair<int, int>> storage;
        for (int i = 0; i < Profits.size(); ++i) {
            heap.push(std::pair<int, int> (Capital[i], Profits[i]));
        }

        for (int i = 1; i <= k; ++i) {
            int weight = res[i - 1];
            if (heap.empty()) return res[i - 1];
            std::pair<int, int> tmp = heap.top();
            while (!heap.empty() && tmp.first > weight) {
                storage.push_back(tmp);
                heap.pop();
                tmp = heap.top();
            }

            if (heap.empty() && tmp.first > weight) return res[i - 1];

            res[i] = res[i - 1] + tmp.second;
            heap.pop();

            while (!storage.empty()) {
                heap.push(storage.back());
                storage.pop_back();
            }
        }

        return res[k];
    }

private:
    struct ComparePair {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };
};


/*
可以使用一个最大堆和一个最小堆，把资本利润对放在最小堆中，这样需要资本小的交易
就在队首，然后从队首按顺序取出资本小的交易，如果所需资本不大于当前所拥有的资本，
那么就把利润资本存入最大堆中，注意这里资本和利润要翻个，因为我们希望把利润最大的
交易放在队首，便于取出，这样也能实现我们的目的
 */

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int, int>> maxH;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        for (int i = 0; i < Capital.size(); ++i) {
            minH.push({Capital[i], Profits[i]});
        }
        for (int i = 0; i < k; ++i) {
            while (!minH.empty() && minH.top().first <= W) {
                auto t = minH.top(); minH.pop();
                maxH.push({t.second, t.first});
            }
            if (maxH.empty()) break;
            W += maxH.top().first; maxH.pop();
        }
        return W;
    }
};
