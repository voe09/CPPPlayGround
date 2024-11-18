class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int r = arr.size() - 1;
        while (r >= 1 && arr[r - 1] <= arr[r])
            r--;

        int res = r;
        int l = 0;
        while (l < r && (l == 0 || arr[l - 1] <= arr[l]))
        {
            while (r < arr.size() && arr[l] > arr[r])
                r++;
            res = min(res, r - l - 1);
            l++;
        }
        return res;
    }
};
