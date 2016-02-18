/*
    Given an array with integers.

    Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| 
        is the largest.

    Return the largest difference.

    Example
        For [1, 2, -3, 1], return 6.

    Note
        The subarray should contain at least one number
*/

/*
    It's a combination of several sub-problems. The idea is to travese the
        array twice, once from the left to the right, and once from the right
        to the left. Record the max and min subarray sum. The result can
        be obtained by max - min.
*/

class Solution {
public:
    int maxDiffSubArrays(vector<int> nums) {
        if (nums.size() < 2) return 0;
        
        int sz = (int)nums.size();

        vector<int> left_max(nums.size()), left_min(nums.size());
        left_max[0] = left_min[0] = nums[0];
        for (int i = 1; i < sz; ++i)
        {
            left_max[i] = max(left_max[i-1]+nums[i], nums[i]);
            left_min[i] = min(left_min[i-1]+nums[i], nums[i]);
        }
        
        int ret = nums[0]-nums[1];
        int right_max_sofar = nums.back(), right_min_sofar = nums.back();
        int right_max_here = nums.back(), right_min_here = nums.back();
        for (int i = sz-2; i >= 0; --i)
        {
            ret = max(ret, left_max[i] - right_min_sofar);
            ret = max(ret, right_max_sofar - left_min[i]);
            right_max_here = max(right_max_here+nums[i], nums[i]);
            right_min_here = min(right_min_here+nums[i], nums[i]);
            right_max_sofar = max(right_max_sofar, right_max_here);
            right_min_sofar = min(right_min_sofar, right_min_here);
        }
        return ret;
    }
};

//It would be clearer if I use more spaces.
class Solution2
{
public:
    int maxDiffSubArrays(vector<int> nums)
    {
        if (nums.size() < 2) return 0;

        int sz = (int)nums.size();

        vector<int> left_max(nums.size()), left_min(nums.size());
        left_max[0] = left_min[0] = nums[0];
        for (int i = 1; i < sz; ++i)
        {
            left_max[i] = max(left_max[i-1]+nums[i], nums[i]);
            left_min[i] = min(left_min[i-1]+nums[i], nums[i]);
        }

        vector<int> right_max(nums.size()), right_min(nums.size());
        right_max.back() = right_min.back() = nums.back();
        int ret = nums[0]-nums[1];
        for (int i = sz - 2; i >= 0; --i)
        {
            right_max[i] = max(right_max[i+1]+nums[i], nums[i]);
            right_min[i] = min(right_min[i+1]+nums[i], nums[i]);
            ret = max(ret, left_max[i] - right_min[i+1]);
            ret = max(ret, right_max[i+1] - left_min[i]);
        }
        return ret;
    }
};
