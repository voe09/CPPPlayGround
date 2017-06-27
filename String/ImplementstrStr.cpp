/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i) {
            if (haystack.substr(i, n) == needle) return i;
        }
        return -1;
    }
};

// KMP algo
// http://bangbingsyb.blogspot.com/2014/11/leetcode-implement-strstr-kmp.html

class Solution {
public:
    vector<int> KMPpreprocessing(char *s) {
        int n = strlen(s);
        vector<int> match(n,-1);
        int j = -1;
        for(int i=1; i<n; i++) {
            while(j>=0 && s[i]!=s[j+1]) j = match[j];
            if(s[i]==s[j+1]) j++;
            match[i] = j;
        }
        return match;
    }


    int strStr(char *haystack, char *needle) {
        if(!*needle) return 0;
        if(!*haystack) return -1;
        int m = strlen(haystack), n = strlen(needle);
        vector<int> match = KMPpreprocessing(needle);
        int j = -1;
        for(int i=0; i<m; i++) {
            while(j>=0 && haystack[i]!=needle[j+1]) j = match[j];
            if(haystack[i]==needle[j+1]) j++;
            if(j==n-1) return (i-n+1);
        }
        return -1;
        
    }
};
