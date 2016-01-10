/*
    Given a sorted array of integers, find the starting and ending 
        position of a given target value.

    Your algorithm's runtime complexity must be in the order of 
        O(log n).

    If the target is not found in the array, return [-1, -1].

    For example,
        Given [5, 7, 7, 8, 8, 10] and target value 8,
        return [3, 4].
*/
        
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {-1, -1};
        int l = lower_bound(nums, target);
        if(l == nums.size() || nums[l] != target) return {-1, -1};
        return {l, lower_bound(nums, target + 1) - 1};
    }
private:
    int lower_bound(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size();
        while(l < h)
        {
            int m = l + ((h - l) >> 1);
            if(nums[m] < target) l = m + 1;
            else h = m;
        }
        return l;
    }
};
