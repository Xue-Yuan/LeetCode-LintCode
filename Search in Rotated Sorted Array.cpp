/*
    Suppose a sorted array is rotated at some pivot unknown to you 
        beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    You are given a target value to search. If found in the array 
        return its index, otherwise return -1.

    You may assume no duplicate exists in the array.
    */

//find minimum first
//then binary search
class Solution 
{
public:
    int search(vector<int> &A, int target) 
    {
        // write your code here
        if (A.empty()) return -1;
        
        int b = 0, e = A.size() - 1;
        while (b <= e)
        {
            int m = b + (e - b) / 2;
            if (A[m] == target) return m;
            if (A[b] <= A[m])
            {
                if (A[b] <= target && target < A[m]) e = m - 1;
                else b = m + 1;
            }
            else
            {
                if (A[m] < target && target <= A[e]) b = m + 1;
                else e = m - 1;
            }
        }
        return -1;
    }
};
