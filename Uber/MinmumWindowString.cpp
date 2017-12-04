/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

string MinWindowStr(string s, string t) {
	unordered_map<char, int> m;
	int cnt = 0;
	for (const auto &c : t) {
		++m[c];
		++cnt;
	}
	
	int left = 0, right = 0;
	string res;
	while (left <= right && right < s.size()) {
		while (right < s.size() && cnt > 0) {
			if (m.count(s[right])) {
				if (m[s[right]] > 0) --cnt;
				--m[s[right]];
			}
			++right;
		}
		
		while (left <= right && cnt == 0) {
			if (m.count(s[left])) {
				if (m[s[left]] == 0) {
					if (res.empty() || res.size() > right - left) {
						res = s.substr(left, right - left);
					}
					++cnt;
				}
				++m[s[left]];
			}
			++left;
		}
	}
	
	return res;
}

int main() {
	cout << MinWindowStr("ADOBECODEBANC", "ABC") << endl;
	cout << MinWindowStr("ab", "a") << endl;
}
