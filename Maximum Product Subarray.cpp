/*
    Find the contiguous subarray within an array (containing at least one number) 
        which has the largest product.

    Example
        For example, given the array [2,3,-2,4], the contiguous subarray [2,3] 
            has the largest product = 6.
*/

class Solution 
{
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) 
    {
        // write your code here
        if (nums.empty()) return 0;
        
        long long maxhere = nums[0], minhere = nums[0], maxsofar = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            long long tmp = maxhere;
            maxhere = max(max((long long)nums[i], maxhere * nums[i])
                , minhere * nums[i]);
            minhere = min(min((long long)nums[i], minhere * nums[i])
                , tmp * nums[i]);
            maxsofar = max(maxsofar, maxhere);
        }
        return (int)maxsofar;
    }
};
