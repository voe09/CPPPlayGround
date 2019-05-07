/*
Given the running logs of n functions that are executed in a nonpreemptive 
single threaded CPU, find the exclusive time of these functions.

Each function has a unique id, start from 0 to n-1. A function may be called
recursively or by another function.

A log is a string has this format : function_id:start_or_end:timestamp. For
example, "0:start:0" means function 0 starts from the very beginning of time 0. 
"0:end:0" means function 0 ends to the very end of time 0.

Exclusive time of a function is defined as the time spent within this function, 
the time spent by calling other functions should not be considered as this 
function's exclusive time. You should return the exclusive time of each function
sorted by their function id.

Example 1:
Input:
n = 2
logs = 
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]
Explanation:
Function 0 starts at time 0, then it executes 2 units of time and reaches the end of time 1. 
Now function 0 calls function 1, function 1 starts at time 2, executes 4 units of time and end at time 5.
Function 0 is running again at time 6, and also end at the time 6, thus executes 1 unit of time. 
So function 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4 units of time.
Note:
Input logs will be sorted by timestamp, NOT log id.
Your output should be sorted by function id, which means the 0th element of 
your output corresponds to the exclusive time of function 0.
Two functions won't start or end at the same time.
Functions could be called recursively, and will always end.
1 <= n <= 100
 */

// https://leetcode.com/articles/exclusive-time-of-functions/#approach-1-using-stack-time-limit-exceeded
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int, int>> stk;
        for (int i = 0; i < logs.size(); ++i) {
            vector<string> tmp = Parser(logs[i]);
            if (tmp[1] == "start") {
                int id = stoi(tmp[0]), time = stoi(tmp[2]);
                stk.push({id, time});
            } else {
                pair<int, int> func = stk.top();
                stk.pop();
                int time = stoi(tmp[2]) - func.second + 1;
                res[func.first] += time;
                if (!stk.empty())
                    res[stk.top().first] -= time;
            }
        }
        return res;
    }

private:
    vector<string> Parser(string& input) {
        string tmp;
        vector<string> res;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] != ':') {
                tmp += input[i];
            } else {
                res.push_back(tmp);
                tmp.clear();
            }
        }
        res.push_back(tmp);
        return res;
    }
};


/**
 * Every time end an function, deduce its life span from its parent
 */
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<pair<int, int>> starters;
        for (int i = 0; i < logs.size(); i++) {
            Line line = getLine(logs[i]);
            if (line.start) {
                starters.push({ line.fid, line.time });
            }
            else {
                pair<int, int> starter = starters.top();
                int lifespan = line.time + 1 - starter.second;
                starters.pop();
                times[line.fid] += lifespan;
                if (!starters.empty()) {
                    times[starters.top().first] -= lifespan;
                }
            }
        }
        return times;
    }

    struct Line {
        int fid;
        bool start;
        int time;
        Line(int fid, bool start, int time) : fid(fid), start(start), time(time) {};
    };

    Line getLine(string s) {
        int colon1 = s.find(":", 0);
        int colon2 = s.find(":", colon1 + 1);
        string fid = s.substr(0, colon1);
        string start = s.substr(colon1 + 1, colon2 - (colon1 + 1));
        string time = s.substr(colon2 + 1);
        return Line(stoi(fid), start == "start", stoi(time));
    }

};
