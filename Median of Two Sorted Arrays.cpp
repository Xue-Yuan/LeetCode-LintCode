/*
    There are two sorted arrays nums1 and nums2 of size m and n 
        respectively. Find the median of the two sorted arrays. 
        The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = (int)nums1.size(), n2 = (int)nums2.size(), median = (n1 + n2) / 2;
        if ((n1 + n2) & 0x1)
            return findKthSortedArrays(nums1, 0, n1, nums2, 0, n2, median + 1);
        else
            return (findKthSortedArrays(nums1, 0, n1, nums2, 0, n2, median) + findKthSortedArrays(nums1, 0, n1, nums2, 0, n2, median + 1)) / 2.0;
    }
    
    double findKthSortedArrays(vector<int> &nums1, int b1, int e1, vector<int> &nums2, int b2, int e2, int k)
    {
        int n1 = e1 - b1, n2 = e2 - b2;
        if (n1 > n2) return findKthSortedArrays(nums2, b2, e2, nums1, b1, e1, k);
        if (n1 <= 0) return nums2[b2 + k - 1];
        if (k == 1) return min(nums1[b1], nums2[b2]);
        
        int i = min(k / 2, n1);
        int j = k - i;
        
        if (nums1[b1 + i - 1] > nums2[b2 + j - 1])
            return findKthSortedArrays(nums1, b1, e1, nums2, b2 + j, e2, k - j);
        else if (nums1[b1 + i - 1] < nums2[b2 + j - 1])
            return findKthSortedArrays(nums1, b1 + i, e1, nums2, b2, e2, k - i);
        return nums1[b1 + i - 1];
    }
};