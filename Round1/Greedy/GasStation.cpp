/*
There are N gas stations along a circular route, where the amount of gas at 
station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel
from station i to its next station (i+1). You begin the journey with an empty
tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit
once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
 */
// gas的总量要大于cost的总量，这样才会有起点的存在。假设开始设置起点start = 0, 
// 并从这里出发，如果当前的gas值大于cost值，就可以继续前进，此时到下一个站点，
// 剩余的gas加上当前的gas再减去cost，看是否大于0，若大于0，则继续前进。
// 当到达某一站点时，若这个值小于0了，则说明从起点到这个点中间的任何一个点都不能
// 作为起点，则把起点设为下一个点，继续遍历。当遍历完整个环时，当前保存的起点即为所求

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        if (total < 0) return -1;
        else return start;
    }
};
