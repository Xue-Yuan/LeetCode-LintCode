/*
    Given an array nums of integers and an int k, partition the array 
        (i.e move the elements in "nums") such that:

    All elements < k are moved to the left
    
    All elements >= k are moved to the right
    
    Return the partitioning index, i.e the first index i nums[i] >= k.

    Example
        If nums = [3,2,2,1] and k=2, a valid answer is 1.

    Note
        You should do really partition in array nums instead of just 
            counting the numbers of integers smaller than k.

    If all elements in nums are smaller than k, then return nums.length
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            while (i < nums.size() && nums[i] < k) ++i;
            while (j >= 0 && nums[j] >= k) --j;
            if (i < j) 
            {
                swap(nums[i], nums[j]);
                ++i, --j;
            }
        }
        return j + 1;
    }
};
