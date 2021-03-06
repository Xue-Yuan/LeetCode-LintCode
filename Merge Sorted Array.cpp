/*
    Given two sorted integer arrays nums1 and nums2, merge nums2 
        into nums1 as one sorted array.
*/
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int idx1 = m - 1, idx2 = n - 1, idx3 = m + n - 1;
        while (idx1 >= 0 && idx2 >= 0)
            nums1[idx3--] = nums1[idx1] > nums2[idx2] ? nums1[idx1--] : nums2[idx2--];
        while (idx1 >= 0)
            nums1[idx3--] = nums1[idx1--];
        while (idx2 >= 0)
            nums1[idx3--] = nums2[idx2--];
    }
};