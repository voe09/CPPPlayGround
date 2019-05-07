/*
Convert roman numeral to integer
*/
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int romanToInt(string s) {
	unordered_map<char, int> lookup {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
									{'C', 100}, {'D', 500}, {'M', 1000}};
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (i == s.size() - 1 || s[i] >= s[i + 1]) res += lookup[s[i]];
		else res -= lookup[s[i]];
	}
	return res;
}

int main() {
	cout << "IV" << ": " << romanToInt("IV") << endl;
	cout << "IX" << ": " << romanToInt("IX") << endl;
	cout << "XII" << ": " << romanToInt("XII") << endl;
	cout << "XIV" << ": " << romanToInt("XIV") << endl;
}

