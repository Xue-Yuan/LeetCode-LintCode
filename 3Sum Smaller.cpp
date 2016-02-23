/*
    Given an array of n integers nums and a target, find the number of index 
        triplets i, j, k with 0 <= i < j < k < n that satisfy the condition 
        nums[i] + nums[j] + nums[k] < target.

    For example, given nums = [-2, 0, 1, 3], and target = 2.

        Return 2. Because there are two triplets which sums are less than 2:

        [-2, 0, 1]
        [-2, 0, 3]
*/

//The requirement of 0 <= i < j < k < n doesn't matter. It only restricts how
//  many times one element can be used.
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size(), cnt = 0;
        for (int i = 0; i < sz-2; ++i)
        {
            int start = i+1, end = sz-1, remain = target-nums[i];
            while (start < end)
                if (nums[start]+nums[end] < remain)
                {
                    cnt += end-start;
                    start++;
                }
                else end--;
        }
        return cnt;
    }
};