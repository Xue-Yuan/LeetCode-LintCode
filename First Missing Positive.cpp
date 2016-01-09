/*
    Given an unsorted integer array, find the first missing 
        positive integer.

    For example,
        Given [1,2,0] return 3,
        and [3,4,-1,1] return 2.

    Your algorithm should run in O(n) time and uses constant space.
*/

//The idea is still to somehow sort the array, at least sort the positive numbers.
class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        if (nums.empty()) return 1;
        
        int idx = 0;        
        while (idx < nums.size())
        {
            //nums[idx] != idx + 1 and nums[idx] != nums[nums[idx] - 1]
            //  we only have to keep the latter.
            while (nums[idx] != idx + 1 && nums[idx] <= nums.size() && nums[idx] >= 1 && nums[idx] != nums[nums[idx] - 1])
                swap(nums[idx], nums[nums[idx] - 1]);
            idx++;
        }
        
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1) return i + 1;
            
        return (int)nums.size() + 1;
    }
};