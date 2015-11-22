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
    int search(vector<int>& nums, int target)
    {
        int mid = findMin(nums, 0, nums.size() - 1);
        int idx1 = search(nums, target, 0, mid-1);
        int idx2 = search(nums, target, mid, nums.size() - 1);
        return (idx1 > idx2) ? idx1 : idx2;
    }
    int findMin(vector<int> &nums, int beg, int end)
    {
        if(beg > end) return 0;
        if(beg == end) return beg;
        if(beg + 1 == end) return (nums[beg] < nums[end]) ? beg : end;
        int mid = beg + (end - beg) / 2;
        if(nums[beg] < nums[end])
            return beg;
        if(nums[beg] > nums[mid])
            return findMin(nums, beg, mid);
        if(nums[mid] > nums[end])
            return findMin(nums, mid + 1, end);
    }
private:
    int search(vector<int> &nums, int t, int b, int e)
    {
        if(b > e) return -1;
        if(b == e) return (nums[b] == t) ? b : -1;
        int mid = b + (e - b) / 2;
        if(t > nums[mid]) return search(nums, t, mid+1, e);
        if(t < nums[mid]) return search(nums, t, b, mid-1);
        return mid;
    }
};