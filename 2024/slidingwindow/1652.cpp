class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + code[i-1];
        
        vector<int> res(n, 0);
        if (k == 0) return res;
        for (int i = 1; i <= n; i++) {
            int s = 0, e = 0;
            if (k > 0) s = i + 1, e = i + k;
            else s = i - abs(k), e = i - 1;
            cout << s << ',' << e << endl;
            if (s > 0 && e <= n) {
                res[i-1] = prefix[e] - prefix[s-1];
            } else if (s <= 0 && e > 0) {
                res[i-1] = prefix[n] - prefix[n+s-1] + prefix[e];
            } else if (s <= 0 && e <= 0) {
                res[i-1] = prefix[n+e] - prefix[n+s-1];
            } else if (s <= n && e > n) {
                res[i-1] = prefix[n] - prefix[s-1] + prefix[e-n];
            } else {
                res[i-1] = prefix[e-n] - prefix[s-n-1];
            }
        }

        return res;
    }
};


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0) return res;

        int start = 1, end = k, sum = 0;
        if (k < 0) {
            start = n - abs(k);
            end = n - 1;
        }

        for (int i = start; i <= end; i++)  sum += code[i];
        for (int i = 0; i < n; i++) {
            res[i] = sum;
            sum -= code[start % n];
            sum += code[(end + 1) % n];
            start++, end++;
        }

        return res;
    }
};