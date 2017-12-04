/*
Given a string, determine if it is a palindrome, considering only alphanumeric 
characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? 
This is a good question to ask during an interview.

For the purpose of this problem, we define empty string
as valid palindrome.
 */
#include <string>
#include <iostream>
using namespace std;

bool isCharacter(char &c) {
    if (c >= 'a' && c <= 'z') return true;
    else if (c >= 'A' && c <= 'Z') {
		c = (c - 'A') + 'a';
		return true;
	} else return false;
}

bool isValid(string s) {
    if (s.empty()) return true;
    int left = 0, right = s.size() - 1;
    while (left <= right) {
        while (left <= right && !isCharacter(s[left])) ++left;
        while (left <= right && !isCharacter(s[right])) --right;
        if (s[left] != s[right]) return false;
        ++left, --right;
    }
    return true;
}

int main() {
    cout << isValid("A man, a plan, a canal: Panama") << endl;
    cout << isValid("asccsa") << endl;
    cout << isValid("ubetrebu") << endl;
}
