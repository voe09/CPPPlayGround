// Task Scheduler
// math - hard
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int mx = 0, mxCnt = 0;
        for (char task : tasks) {
            freq[task - 'A']++;
            if (mx == freq[task - 'A']) {
                ++mxCnt;
            } else if (mx < freq[task - 'A']) {
                mx = freq[task - 'A'];
                mxCnt = 1;
            }
        }

        int partNum = mx - 1;
        int partLen = n - (mxCnt - 1);
        int emptySlots = partNum * partLen;
        int taskLeft = tasks.size() - mx * mxCnt;
        int idle = max(0, emptySlots - taskLeft);
        return tasks.size() + idle;
    }
};

// priority queue solution
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqs;
        for (char task : tasks)
            freqs[task]++;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comp> pq;
        for (auto& pair : freqs) {
            pq.push({pair.first, pair.second});
        }

        int idle = 0;
        while (!pq.empty()) {
            vector<pair<char, int>> tmp;
            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    pair<char, int> t = pq.top();
                    pq.pop();
                    if (--t.second > 0) tmp.push_back(t);
                } else {
                    if (!tmp.empty()) idle++;
                }
            }

            for (pair<char, int>& t : tmp) {
                pq.push(t);
            }
        }

        return tasks.size() + idle;
    }

    struct Comp {
        bool operator()(pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        }
    };
};