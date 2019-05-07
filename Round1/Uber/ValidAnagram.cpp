/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
	vector<int> cnts (26, 0);
	for (const auto &c : s) {
		++cnts[c - 'a'];
	}
	
	for (const auto &c : t) {
		--cnts[c - 'a'];
	}
	
	for (const auto &cnt : cnts) {
		if (cnt != 0) return false;
	}
	return true;
}


int main() {
	cout << isAnagram("anagram", "nagaram") << endl;
	cout << isAnagram("rat", "cat") << endl;
}

