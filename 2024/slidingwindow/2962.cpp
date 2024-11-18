#include <vector>
#include <deque>
#include <iostream>

using namespace std;

// TLE - over complicated
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        deque<int> q;
        for (int i = 0; i < nums.size(); i++)
        {
            if (q.empty() || nums[q.back()] == nums[i])
                q.push_back(i);
            else if (nums[q.back()] < nums[i])
            {
                q.clear();
                q.push_back(i);
            }
        }

        int mx = q.size();

        q.push_front(-1);
        q.push_back(nums.size());

        long long res = 0;

        for (int j = k; j <= mx; j++)
        {
            deque<int> t = q;
            deque<int> dq;
            while (!t.empty())
            {

                dq.push_back(t.front());
                t.pop_front();
                if (dq.size() == j + 2)
                {
                    long long l = dq.front();
                    dq.pop_front();
                    l = dq.front() - l;
                    long long tmp = dq.back();
                    dq.pop_back();
                    int r = tmp - dq.back();
                    dq.push_back(tmp);
                    res += l * r;
                }
            }
        }

        return res;
    }
};

// class Solution
// {
// public:
//     long long countSubarrays(vector<int> &nums, int k)
//     {
//         int mx = *max_element(nums.begin(), nums.end());
//         vector<int> q;
//         long long res = 0;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == mx)
//             {
//                 q.push_back(i);
//             }

//             int s = q.size();
//             if (s >= k)
//             {
//                 res += q[s - k] + 1;
//             }
//         }
//         return res;
//     }
// };


int main() {
    Solution sol = Solution();
    cout << sol.countSubarrays({1, 3, 3, 3, 3}, 2) << endl;
    
}
