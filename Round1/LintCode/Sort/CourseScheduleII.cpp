/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to
first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the
ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If
it is impossible to finish all courses, return an empty array.

Have you met this question in a real interview? Yes
Example
Given n = 2, prerequisites = [[1,0]]
Return [0,1]

Given n = 4, prerequisites = [1,0],[2,0],[3,1],[3,2]]
Return [0,1,2,3] or [0,2,1,3]
 */

class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here
        vector<vector<int>> graph(numCourses);
        vector<int> cnts(numCourses, 0);
        for (const auto &pair : prerequisites) {
            graph[pair.second].push_back(pair.first);
            ++cnts[pair.first];
        }
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (cnts[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            res.push_back(course);
            for (const auto &c : graph[course]) {
                --cnts[c];
                if (cnts[c] == 0) q.push(c);
            }
        }

        if (res.size() != numCourses) return {};
        return res;
    }
};
