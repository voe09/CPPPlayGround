/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have 
to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it
possible for you to finish all courses?

Have you met this question in a real interview? Yes
Example
Given n = 2, prerequisites = [[1,0]]
Return true

Given n = 2, prerequisites = [[1,0],[0,1]]
Return false
 */

class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here
        vector<vector<int>> graph(numCourses);
        vector<int> pres(numCourses, 0);
        for (const auto &pair : prerequisites) {
            ++pres[pair.first];
            graph[pair.second].push_back(pair.first);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (pres[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            for (const auto &neighbor : graph[course]) {
                --pres[neighbor];
                if (pres[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (pres[i] != 0) return false;
        }
        return true;
    }
};
