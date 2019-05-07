/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/
class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        if (s.empty())
            return 0;
        unordered_map<char, int> repeats;
        int left = 0;
        int maxLength = 0;
        for (int right = 0; right < s.length(); right++)
        {
            char c = s[right];
            repeats[c]++;
            if (repeats.size() > 2)
            {
                maxLength = max(maxLength, right - left);
                while (left < right && repeats.size() > 2)
                {
                    repeats[s[left]]--;
                    if (!repeats[s[left]])
                    {
                        repeats.erase(s[left]);
                    }
                    left++;
                    if (repeats.size() <= 2)
                    {
                        break;
                    }
                }
            }
        }
        return max(static_cast<int>(s.length()) - left, maxLength);
    }
};