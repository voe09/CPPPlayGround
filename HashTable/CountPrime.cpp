/*
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

// Time limit exceeded
class Solution {
public:
    int countPrimes(int n) {
        set<int> set;
        for (int i = 2; i < n; ++i) {
            set.insert(i);
        }

        for (int i = 2; i < n; ++i) {
            if (set.count(i)) {
                int start = 2;
                int tmp = i * start;
                while (tmp < n) {
                    if (set.count(tmp)) set.erase(tmp);
                    ++start;
                    tmp = i * start;
                }
            }
        }
        return set.size();
    }
};

class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2) return 0;
		bool * isPrimer = new bool[n];
		for (int i = 0; i < n; i++)	isPrimer[i] = true;
		for (int i = 2; i * i < n; i++) {
			if (isPrimer[i])
				for (int j = i ; j * i < n; j ++)
					isPrimer[j * i] = false;
		}
		int res = 0;
		for (int i = 2; i < n; i++)
			if (isPrimer[i]) res++;
		delete[] isPrimer;
		return res;
	}
};

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> is_prime(n - 1, true);
        for (int i = 2; i < n; ++i) {
            if (!is_prime[i - 2]) continue;

            for (int k = 2; i * k < n; ++k) {
                if (is_prime[i * k - 2]) is_prime[i * k - 2] = false;
            }
        }
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i - 2]) ++res;
        }
        return res;
    }
};
