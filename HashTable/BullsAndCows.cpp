/*
You are playing the following Bulls and Cows game with your friend: 
You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates 
how many digits in said guess match your secret number exactly in both digit 
and position (called "bulls") and how many digits match the secret number 
but locate in the wrong position (called "cows"). Your friend will use 
successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number 
and friend's guess, use A to indicate the bulls and B to indicate the cows. 
In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may 
contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow,
and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits,
and their lengths are always equal.
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int, set<int>> map;
        for (int i = 0; i < secret.size(); ++i) {
            int num = secret[i] - '0';
            if (map.count(num)) {
                map[num].insert(i + 1);
            } else {
                map[num] = {i + 1};
            }
        }

        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < guess.size(); ++i) {
            int num = guess[i] - '0';
            if (map.count(num)) {
                if (map[num].count(i + 1)) {
                    ++bulls;
                    map[num].erase(i + 1);
                    if (map[num].empty())
                        map.erase(num);
                }
                else {
                    map[num].insert(-(i + 1));
                }
            }
        }
        
        for (const auto& pair: map) {
            int pos = 0;
            int neg = 0;
            for (const auto& num: pair.second) {
                if (num > 0) ++pos;
                else ++neg;
            }
            cows += min(pos, neg);
        }

        string res = "";
        res = res + to_string(bulls) + 'A' + to_string(cows) + 'B';
        return res;
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> s_lookup, g_lookup;
        int A = 0, B = 0;
        const int n = min(secret.length(), guess.length());
        for (int i = 0; i < n; ++i) {
            const char s = secret[i];
            const char g = guess[i];
            if (s == g) {
                ++A;
            } else {
                (s_lookup[g] > 0) ? --s_lookup[g], ++B : ++g_lookup[g];
                (g_lookup[s] > 0) ? --g_lookup[s], ++B : ++s_lookup[s]; 
             }
        }
        return to_string(A).append("A").append(to_string(B)).append("B");
    }
};
