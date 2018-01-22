/*
Numbers keep coming, return the median of numbers at every time a new number added.

Have you met this question in a real interview? Yes
Clarification
What's the definition of Median?
- Median is the number that in the middle of a sorted array. If there are n 
numbers in a sorted array A, the median is A[(n - 1) / 2]. For example, 
if A=[1,2,3], median is 2. If A=[1,19], median is 1.

Example
For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3].

For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3].

For numbers coming list: [2, 20, 100], return [2, 2, 20].

Challenge 
Total run time in O(nlogn).
 */

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        priority_queue<int, vector<int>, std::greater<int>> minHeap;
        priority_queue<int> maxHeap;
        
        vector<int> res;
        for (const auto &num : nums) {
            if (minHeap.empty() || minHeap.top() >= num)
                maxHeap.push(num);
            else {
                if (minHeap.top() < num) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            res.push_back(maxHeap.top());
        }
        return res;
    }
};
