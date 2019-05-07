/*
Given two numbers n and k. We need to find out if n can
be written as sum of k prime numbers.

 Notice

n <= 10 ^ 9

Goldbach's conjecture

Example
Given n = 10, k = 2
Return true   // 10 = 5 + 5

Given n = 2, k = 2
Return false
 */

/*
The idea is to use Goldbach’s conjecture which says that every
even integer (greater than 2) can be expressed as sum of two primes.

If the N = 2K and K = 1 : the answer will be Yes iff N is a prime number

If N >= 2K and K = 2 : If N is an even number answer will be 
Yes(Goldbach’s conjecture) and if N is odd answer will be No if N-2 
is not a prime number and Yes if N-2 is a prime number. This is because
we know odd + odd = even and even + odd = odd. So when N is odd, 
and K = 2 one number must be 2 as it is the only even prime number so 
now the answer depends whether N-2 is odd or not.
If N >= 2K and K >= 3 : Answer will always be Yes. When N is even
N – 2*(K-2) is also even so N – 2*(K – 2) can be written as sum of 
two prime numbers (Goldbach’s conjecture) p, q and N can be written
as 2, 2 …..K – 2 times, p, q. When N is odd N – 3 -2*(K – 3) is
even so it can be written as sum of two prime numbers p, q and
N can be witten as 2, 2 …..K-3 times, 3, p, q
 */

class Solution {
public:
    /*
     * @param : an int
     * @param : an int
     * @return: if N can be expressed in the form of sum of K primes
     * ,return true; otherwise, return false.
     */
    bool isSumOfKPrimes(int n, int k) {
        // write your code here
        if (n < 2 * k) return false;

        if (k == 1) return isPrime(n);

        if (k == 2) {
            if (n % 2 == 0) return true;
            return isPrime(n - 2);
        }
        return true;
    }

private:
    bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }
};
