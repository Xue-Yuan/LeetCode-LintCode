/*
    Given an array of integers, find two non-overlapping subarrays which 
        have the largest sum.

    The number in each subarray should be contiguous.
    
    Return the largest sum.

    Example
        For given [1, 3, -1, 2, -1, 2], the two subarrays are 
        [1, 3] and [2, -1, 2] or [1, 3, -1, 2] and [2], they both have 
        the largest sum 7.
*/

class Solution {
public:
    int maxTwoSubArrays(vector<int> nums) {
        if (nums.size() < 2) return 0;
        
        vector<int> left_max(nums.size());
        left_max[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
            left_max[i] = max(left_max[i-1]+nums[i], nums[i]);
            
        int max_here = nums.back(), max_sofar = nums.back();
        int ret = nums[0]+nums[1];
        for (int i = (int)nums.size()-2; i >= 0; --i)
        {
            ret = max(ret, max_sofar+left_max[i]);
            max_here = max(max_here+nums[i], nums[i]);
            max_sofar = max(max_sofar, max_here);
        }
        return ret;
    }
};
