/*
Given an integer array, sort it in ascending order. 
Use selection sort, bubble sort, insertion sort or any O(n2) algorithm.

Example
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].
 */

// Selection Sort
class Solution {
public:
    /*
     * @param A: an integer array
     * @return:
     */
    void sortIntegers(vector<int> &A) {
        // write your code here
        for (int i = 0; i < A.size(); ++i) {
            int minVal = i;
            for (int j = i; j < A.size(); ++j) {
                if (A[minVal] > A[j]) minVal = j;
            }
            swap(A[i], A[minVal]);
        }
    }
};

// Insertion Sort
class Solution {
public:
    /*
     * @param A: an integer array
     * @return: 
     */
    void sortIntegers(vector<int> &A) {
        // write your code here
        for (int i = 1; i < A.size(); ++i) {
            int key = A[i];
            int j = i - 1;
            while (j >= 0 && A[j] > key) {
                A[j + 1] = A[j];
                j = j - 1;
            }
            A[j + 1] = key;
        }
    }
};

// Bubble Sort
class Solution {
public:
    /*
     * @param A: an integer array
     * @return: 
     */
    void sortIntegers(vector<int> &A) {
        // write your code here
        int n = A.size();
        for (int i = 0; i < n - 1; ++i) {
            // last i elements are already in place
            for (int j = 0; j < n - i - 1; ++j) {
                if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
            }
        }
    }
};
