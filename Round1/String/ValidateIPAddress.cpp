/*
Write a function to check whether an input string is a valid IPv4 address or 
IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, 
which consists of four decimal numbers, each ranging from 0 to 255, 
separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. 
For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, 
each group representing 16 bits. The groups are separated by colons (":"). 
For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. 
Also, we could omit some leading zeros among four hexadecimal digits 
and some low-case characters in the address to upper-case ones, 
so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit 
leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single 
empty group using two consecutive colons (::) to pursue simplicity. 
For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, 
the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters 
in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.empty()) return "Neither";
        bool IPv4 = true, IPv6 = true;
        if (IP[IP.size() - 1] == ':' || IP[IP.size() - 1] == '.') return "Neither";
        int cnt = 0;
        for (int i = 0; i < IP.size(); ++i) {
            string tmp;
            while (i < IP.size() && (IP[i] != '.' && IP[i] != ':')) {
                tmp = tmp + IP[i];
                ++i;
            }
            cnt += 1;
            if (tmp.empty()) return "Neither";
            std::cout << "string1: " << tmp << std::endl;
            if ((i < IP.size() && IP[i] == '.') || (i == IP.size() && IPv4)) {
                if (cnt > 4) return "Neither";
                std::cout << tmp << std::endl;
                IPv6 = false;
                if (!IPv4) return "Neither";
                if (tmp.size() > 3) return "Neither";
                if (tmp.size() > 1 && tmp[0] == '0') return "Neither";
                // Check 0 <= tmp <= 255
                int num = 0;
                for (int j = 0; j < tmp.size(); ++j) {
                    if (!(tmp[j] >= '0' && tmp[j] <= '9')) return "Neither";
                    num = num * 10 + (tmp[j] - '0');
                }
                std::cout << "number:" << num << std::endl;
                if (num > 255) return "Neither";
            } else if ((i < IP.size() && IP[i] == ':') || (i == IP.size() && IPv6)) {
                if (cnt > 8) return "Neither";
                std::cout << "string: " << tmp << std::endl;
                IPv4 = false;
                if (!IPv6) return "Neither";
                if (tmp.size() > 4 || tmp.size() == 0) return "Neither";
                for (int j = 0; j < tmp.size(); ++j) {
                    if (!((tmp[j] >= '0' && tmp[j] <= '9') || (tmp[j] >= 'a'
                        && tmp[j] <= 'f') || (tmp[j] >= 'A' && tmp[j] <= 'F')))
                        return "Neither";
                }
            }
        }
        if (cnt == 4 && IPv4) return "IPv4";
        if (cnt == 8 && IPv6) return "IPv6";
        return "Neither";
    }
};
