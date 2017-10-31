/*
There are ·n· different online courses numbered from 1 to n. Each course has 
some duration(course length) t and closed on dth day. A course should be taken 
continuously for t days and must be finished before or on the dth day. You will
start at the 1st day.

Given n online courses represented by pairs (t,d), your task is to find the 
maximal number of courses that can be taken.

 Notice

The integer 1 <= d, t, n <= 10,000.
You can't take two courses simultaneously.
Have you met this question in a real interview? Yes
Example
Given [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
return 3

There're totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th
day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 
1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 
1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day,
which exceeds the closed date.
 */

class Solution {
public:
    /*
     * @param : duration and close day of each course
     * @return: the maximal number of courses that can be taken
     */
    int scheduleCourse(vector<vector<int>> &courses) {
        // write your code here
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){
                return a[1] < b[1];
            });
        priority_queue<int> heap;
        int curTime = 0;
        for (const auto& course : courses) {
            curTime += course[0];
            heap.push(course[0]);
            while (curTime > course[1]) {
                curTime -= heap.top();
                heap.pop();
            }
        }
        return heap.size();
    }
};