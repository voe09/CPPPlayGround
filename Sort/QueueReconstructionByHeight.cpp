/*
Suppose you have a random list of people standing in a queue. Each person is 
described by a pair of integers (h, k), where h is the height of the person and 
k is the number of people in front of this person who have a height greater 
than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        std::sort(people.begin(), people.end(), [](const pair<int, int>& a,
                  const pair<int, int>& b) { return a.first > b.first ||
                (a.first == b.first && a.second < b.second)});
        vector<pair<int, int>> res;
        for (const auto& a: people) {
            res.insert(res.begin() + a.second, a);
        }
        return res;
    }
};


/*
不使用额外空间的解法，这种方法没有没有使用vector自带的insert或者erase函数，
而是通过一个变量cnt和k的关系来将元素向前移动到正确位置，移动到方法是通过每次跟
前面的元素交换位置
 */

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        std::sort(people.begin(), people.end(), [](const pair<int, int>& a,
                const pair<int, int>& b) { return a.first > b.first ||
                (a.first == b.first && a.second < b.second);});

        for (int i = 0; i < people.size(); ++i) {
            int cnt = 0, j = 0;
            int h = people[i].first, k = people[i].second;
            while (j < i) {
                if (people[j].first >= h) ++cnt;
                ++j;
            }

            int curr = i;
            int prev = i - 1;
            while (cnt > k) {
                std::swap(people[curr--], people[prev--]);
                --cnt;
            }
        }
        return people;
    }
};
