/*
Given a set of n nuts of different sizes and n bolts of different sizes. 
There is a one-one mapping between nuts and bolts. Comparison of a nut to
another nut or a bolt to another bolt is not allowed. It means nut can only be
compared with bolt and bolt can only be compared with nut to see which one is
bigger/smaller.

We will give you a compare function to compare nut with bolt.

Have you met this question in a real interview? Yes
Example
Given nuts = ['ab','bc','dd','gg'], bolts = ['AB','GG', 'DD', 'BC'].

Your code should find the matching bolts and nuts.

one of the possible return:

nuts = ['ab','bc','dd','gg'], bolts = ['AB','BC','DD','GG'].

we will tell you the match compare function. If we give you another compare function.

the possible return is the following:

nuts = ['ab','bc','dd','gg'], bolts = ['BC','AA','DD','GG'].

So you must use the compare function that we give to do the sorting.

The order of the nuts or bolts does not matter. You just need to find the matching bolt for each nut.
 */

/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        sortNutsAndBolts(nuts, bolts, 0, nuts.size() - 1, compare);
    }

private:
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts,
            int left, int right, Comparator compare) {
        int idx = left;
        for (; idx <= right; ++idx) {
            if (compare.cmp(nuts[left], bolts[idx]) == 0) break;
        }

        swap(bolts[left], bolts[idx]);
        
    }
};




首先结合例子读懂题意，本题为 nuts 和 bolts 的配对问题，但是需要根据题目所提供的
比较函数，且 nuts 与 nuts 之间的元素无法直接比较，compare 仅能在 nuts 与 bolts 
之间进行。首先我们考虑若没有比较函数的限制，那么我们可以分别对 nuts 和 bolts 
进行排序，由于是一一配对，故排完序后即完成配对。那么在只能通过比较对方元素得知
相对大小时怎么完成排序呢?

我们容易通过以一组元素作为参考进行遍历获得两两相等的元素，这样一来在最坏情况下
时间复杂度为 O(n2)O(n^2)O(n2), 相当于冒泡排序。根据排序算法理论可知基于比较的排序
算法最好的时间复杂度为 O(nlogn)O(n \log n)O(nlogn), 也就是说这道题应该是可以进一步
优化。回忆一些基于比较的排序算法，能达到 O(nlogn)O(n \log n)O(nlogn) 时间复杂度的
有堆排、归并排序和快速排序，由于这里只能通过比较得到相对大小的关系，故可以联想到
快速排序。

快速排序的核心即为定基准，划分区间。由于这里只能以对方的元素作为基准，故一趟划分
区间后仅能得到某一方基准元素排序后的位置，那通过引入 O(n)O(n)O(n) 的额外空间来对
已处理的基准元素进行标记如何呢？这种方法实现起来较为困难，因为只能对一方的元素划分
区间，而对方的元素无法划分区间进而导致递归无法正常进行。

山穷水尽疑无路，柳暗花明又一村。由于只能通过对方进行比较，故需要相互配合进行 
partition 操作(这个点确实难以想到)。核心在于：首先使用 nuts 中的某一个元素作为基准
对 bolts 进行 partition 操作，随后将 bolts 中得到的基准元素作为基准对 nuts 进行 
partition 操作。

class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        if (nuts.empty() || bolts.empty()) return;
        if (nuts.size() != bolts.size()) return;

        qsort(nuts, bolts, compare, 0, nuts.size() - 1);
    }

private:
    void qsort(vector<string>& nuts, vector<string>& bolts, Comparator compare,
               int l, int u) {

        if (l >= u) return;
        // find the partition index for nuts with bolts[l]
        int part_inx = partition(nuts, bolts[l], compare, l, u);
        // partition bolts with nuts[part_inx]
        partition(bolts, nuts[part_inx], compare, l, u);
        // qsort recursively
        qsort(nuts, bolts, compare, l, part_inx - 1);
        qsort(nuts, bolts, compare, part_inx + 1, u);
    }

    int partition(vector<string>& str, string& pivot, Comparator compare,
                  int l, int u) {

        int m = l;
        for (int i = l + 1; i <= u; ++i) {
            if (compare.cmp(str[i], pivot) == -1 ||
                compare.cmp(pivot, str[i]) == 1) {

                ++m;
                std::swap(str[m], str[i]);
            } else if (compare.cmp(str[i], pivot) == 0 ||
                       compare.cmp(pivot, str[i]) == 0) {
                // swap nuts[l]/bolts[l] with pivot
                std::swap(str[i], str[l]);
                --i;
            }
        }
        // move pivot to proper index
        std::swap(str[m], str[l]);

        return m;
    }
};
