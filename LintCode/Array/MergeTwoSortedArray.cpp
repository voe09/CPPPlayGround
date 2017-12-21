/*
Merge two given sorted integer array A and B into a new sorted 
integer array.

Example
A=[1,2,3,4]

B=[2,4,5,6]

return [1,2,2,3,4,4,5,6]

Challenge 
How can you optimize your algorithm if one array is very large and the other is very small?
*/

class Solution {
public:
    /*
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int m = A.size(), n = B.size();
        if (m < n) return mergeSortedArray(B, A);
        A.resize(m + n);
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
        return A;
    }
};
