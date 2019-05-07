/*
Given an input string and ordering string, need to return true if the ordering
string is present in input string.

Input = "hello world!"
ordering = "hlo!"
result = FALSE (all Ls are not before all Os)

input = "hello world!"
ordering = "!od"
result = FALSE (the input has '!' comming after 'o' and after 'd',
                but the pattern needs it to come before 'o' and 'd')

input = "aaaabbbbcccc"
ordering = "ac"
result = True
 */

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

bool isMatch(string &s, string &o) {
    unordered_map<char, int> lookup;
    for (int i = 0; i < o.size(); ++i) {
        lookup[o[i]] = i;
    }
    
    vector<int> seq;
    for (const auto &c : s) {
        if (lookup.count(c)) {
            seq.push_back(lookup[c]);
        }
    }
    
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[i - 1]) return false;
    }
    
    return true;
}

int main() {
    string input = "hello world!";
    string order = "hlo!";
    std::cout << isMatch(input, order) << std::endl;
    
    order = "hel!";
    std::cout << isMatch(input, order) << std::endl;
}
