/*
Given two sorted integer arrays A and B, merge B into A 
as one sorted array.

You may assume that A has enough space (size that is 
greater or equal to m + n) to hold additional elements
from B. The number of elements initialized in A and B
are m and n respectively.

Have you met this question in a real interview? Yes
Example
A = [1, 2, 3, empty, empty], B = [4, 5]

After merge, A will be filled as [1, 2, 3, 4, 5]
*/

class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int p1 = m - 1, p2 = n - 1;
        for (int i = m + n - 1; i >= 0; --i) {
            if (p1 >= 0 && p2 >= 0) {
                A[i] = (A[p1] > B[p2]) ? A[p1--] : B[p2--];
            } else if (p1 >= 0) {
                A[i] = A[p1--];
            } else {
                A[i] = B[p2--];
            }
        }
    }
};
