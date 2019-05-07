/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

// http://www.cnblogs.com/grandyang/p/4389572.html

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){  // rotate a layer
                swap(matrix[a][a+i], matrix[a+i][b]); // 先按x轴翻转
                swap(matrix[a][a+i], matrix[b][b-i]); // 再按对角线翻转
                swap(matrix[a][a+i], matrix[b-i][a]); // 最后按y轴翻转
            }
            ++a;
            --b;
        }
    }
};
