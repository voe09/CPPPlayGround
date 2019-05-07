/*
A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', 
which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', 
return the total number of ways to decode it.

Also, since the answer may be very large, you should return 
the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", 
"C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
 */

// dp[x] = (dp[x - 2] * dmap[s[x - 1 .. x]] + dp[x - 1] * dmap[s[x]]) % MOD

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1) {
            if (s[0] == '*') return 9;
            else return 0;
        }
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        if (s[0] == '0') return 0;
        if (s[0] == '*')
            dp[1] = 9;
        else
            dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == '*' && s[i - 2] == '*') {
                dp[i] = 9 * dp[i - 1] + 15 * dp[i - 2];  
            } else if (s[i - 1] == '*') {
                if (s[i - 2] > '2' || s[i - 2] == '0') {
                    dp[i] = 9 * dp[i - 1];
                } else if (s[i - 2] == '1') {
                    dp[i] = 9 * dp[i - 1] + 9 * dp[i - 2];
                } else if (s[i - 2] == '2') {
                    dp[i] = 9 * dp[i - 1] + 6 * dp[i - 2];
                }
            } else if (s[i - 2] == '*') {
                if (s[i - 1] > '6') {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else if (s[i - 1] > '0') {
                    dp[i] = dp[i - 1] + 2 * dp[i - 2];
                } else {
                    dp[i] = 2 * dp[i - 2];
                }
            } else {
                int val = 10 * (s[i - 2] - '0') + (s[i - 1] - '0');
                if (val <= 26 && val > 9) dp[i] += dp[i - 2];
                if (s[i] != '0') dp[i] += dp[i - 1];
                if (dp[i] == 0) return 0;
            }
            dp[i] %= 100000007;
        }
        return dp[n] % (100000007);
    }
};


int numDecodings(string s) {
    int n = s.size();
    if(n < 1) return 0;
    vector<long> dp(n+1, 0);
    dp[0] = 1;
    if(s[0] == '*'){
        dp[1] = 9;
    }else if(s[0] - '0' > 0){
        dp[1] = 1;
    }
    int base;
    base = 1000000000 + 7;
    int single; // number of ways using 1 digit
    int Double; // number of ways using 2 digits
    for(int i = 2; i <= n; i++){
        if(isdigit(s[i-1])){ // current position is a number
            single = 1;
            Double = 0;
            if(s[i-1] - '0' == 0){
                single = 0;
            }
            if(isdigit(s[i-2])){
                if(s[i-2] - '0' > 0){
                    int val = (s[i-2] - '0') * 10 + s[i-1] -'0';
                    if(val <= 26){
                        Double = 1;
                    }
                }
            }else{
                int val = s[i-1] - '0';
                if(val <= 6){
                    Double = 2;
                }else{
                    Double = 1;
                }
            }
            dp[i] = ((dp[i-1] * single) % base + (dp[i-2] * Double) % base) % base ;
        }else{
            single = 9;
            Double = 0;
            if(isdigit(s[i-2])){
                if(s[i-2] - '0' == 0){
                    Double = 0;
                }else if(s[i-2] - '0' == 1){
                    Double = 9;
                }else if(s[i-2] - '0' == 2){
                    Double = 6;
                }else{
                    Double = 0;
                }
            }else{
                Double = 9 + 6;
            }
            dp[i] = ((dp[i-1] * single) % base + (dp[i-2] * Double) % base) % base ;
        }
    }
    return dp[n];
}
