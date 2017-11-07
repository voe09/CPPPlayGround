/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity
should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 */

/*
median of the two sorted arrays is the (m+n)/2+1 th element (if m+n is odd),
the average of (m+n)/2 th and (m+n)/2+1 th  (if m+n is even).
Our task becomes finding the Kth (K or K+1, K=(m+n)/2) number in two sorted 
arrays, in O(log(m+n)) time constraint
Our task becomes finding the Kth (K or K+1, K=(m+n)/2) number in two sorted
arrays, in O(log(m+n)) time constraint (what's in your mind to see log? 
Yes, binary search).

Similar to but slight different from binary search, we still divide K into two
halves each time. Two pointers are used for each array, so that we can compare 
which side is smaller (?A[pa]>B[pb]).
E.g., A = [1,3,5,7,9]  B = [2,4,8,10,12,14,16,18]. K=(5+8) /2= 6.

pa = K/2 = 3;
pb = K-pa = 3;
         pa
A[1,3,5,7,9]
         pb
B[2,4,8,10,12,14,16,18]

if (A[pa]<B[pb]), which means the elements from A[0] to A[pa] must exist in the
first Kth elements.
The next step now becomes finding the (K-pa) th (equals to K/2) element in the
array A[pa:end] and B[].  This procedure can be viewed as "cutting" K/2 elements
from the "smaller" array, and continue find the other K/2 th elements from the
"bigger" array and the array after the cut. Note that smaller and bigger here
is the comparison of the last elements.

if (A[pa]>B[pb]), the same procedure is applied but we "cut" the B array.

In this way, every time we have "cut" K/2 elements from one of the arrays,
the next time is to cut (K/2) /2 elements from the new arrays, until:
(1) K=1, the smaller one from A[0] and B[0] is the "Kth element".
(2) One of the array meets the end. Then just return the current Kth element from the other array.
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1) {
            return findKth(nums1, 0, nums2, 0, total / 2 + 1);
        } else {
            return (findKth(nums1, 0, nums2, 0, total / 2) + findKth(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
        }
    }

    double findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j) return findKth(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int pa = min(i + k / 2, int(nums1.size())), pb = j + k - pa + i;
        if (nums1[pa - 1] < nums2[pb - 1])
            return findKth(nums1, pa, nums2, j, k - pa + i);
        else if (nums1[pa - 1] > nums2[pb - 1])
            return findKth(nums1, i, nums2, pb, k - pb + j);
        else
            return nums1[pa - 1];
    }
};



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        if (length % 2 == 0)
            return (findKthElementInSortedArrays(nums1, 0, nums2, 0, length / 2)
                    + findKthElementInSortedArrays(nums1, 0, nums2, 0, length / 2 + 1)) / 2;
        else
            return findKthElementInSortedArrays(nums1, 0, nums2, 0, length / 2 + 1);
    }

private:
    double findKthElementInSortedArrays(vector<int>& nums1, int i,
            vector<int>& nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j) return findKthElementInSortedArrays(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int pa = min(i + k / 2, static_cast<int>(nums1.size())), pb = j + (k - (pa - i));
        if (nums1[pa - 1] < nums2[pb - 1])
            return findKthElementInSortedArrays(nums1, pa, nums2, j, k - (pa - i));
        else if (nums1[pa - 1] > nums2[pb - 1])
            return findKthElementInSortedArrays(nums1, i, nums2, pb, k - (pb - j));
        else return nums1[pa - 1];
    }
};
