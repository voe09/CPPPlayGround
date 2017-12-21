/*
There are N gas stations along a circular route, where the amount of gas at
station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to 
travel from station i to its next station (i+1). You begin the journey with
an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit
once, otherwise return -1.

 Notice

The solution is guaranteed to be unique.

Have you met this question in a real interview? Yes
Example
Given 4 gas stations with gas[i]=[1,1,3,1], and the cost[i]=[2,2,1,1]. 
The starting gas station's index is 2.

Challenge 
O(n) time and O(1) extra space
 */

class Solution {
public:
    /*
     * @param gas: An array of integers
     * @param cost: An array of integers
     * @return: An integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        if (gas.empty()) return -1;
        int start = 0, total = 0, sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }

        if (total < 0) return -1;
        return start;
    }
};
