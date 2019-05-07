/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.Given a string, find the length of the longest substring without repeating characters.

	     Example 1:

	     Input: "abcabcbb"
	     Output: 3 
	     Explanation: The answer is "abc", with the length of 3. 
	     Example 2:

	     Input: "bbbbb"
	     Output: 1
	     Explanation: The answer is "b", with the length of 1.
	     Example 3:

	     Input: "pwwkew"
	     Output: 3
	     Explanation: The answer is "wke", with the length of 3. 
	                  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
class Solution {
	public:
		    int lengthOfLongestSubstring(string s) {
			        if (s.empty()) return 0;
				    int maxLength = 0;
				        int left = 0;
					    unordered_set<char> exists;
					        for (int right = 0; right < s.length(); right++) {
							        char c = s[right];
								        if (exists.count(c) > 0) {
										            maxLength = max(right - left, maxLength);
											                while (s[left] != c) {
														                exists.erase(s[left++]);
																            }
													            left++;
														            }
									        exists.insert(c);
										    }
						    return max(static_cast<int>(s.length()) - left, maxLength);
						        }
};
