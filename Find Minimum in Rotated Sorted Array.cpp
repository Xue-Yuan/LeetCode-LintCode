/*
    Suppose a sorted array is rotated at some pivot unknown to you 
        beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.

    Example
        Given [4, 5, 6, 7, 0, 1, 2] return 0

    Note
        You may assume no duplicate exists in the array.
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int b = 0, e = (int)num.size() - 1;
        while (b < e)
        {
            if (num[b] < num[e]) return num[b];
            int m = b + (e - b) / 2;
            if (num[b] > num[m]) e = m;
            else b = m + 1;
        }
        return num[b];
    }
};