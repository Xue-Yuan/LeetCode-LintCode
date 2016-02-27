/*
    Given n balloons, indexed from 0 to n-1. Each balloon is painted with a 
        number on it represented by array nums. You are asked to burst all 
        the balloons. If the you burst balloon i you will get 
        nums[left] * nums[i] * nums[right] coins. Here left and right are 
        adjacent indices of i. After the burst, the left and right then becomes 
        adjacent.

    Find the maximum coins you can collect by bursting the balloons wisely.

    Note: 
    (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore 
        you can not burst them.
    (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

    Example:

    Given [3, 1, 5, 8]

    Return 167

        nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
       coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), 0));
        return burst(nums, 0, (int)nums.size()-1, memo);
    }
private:
    int burst(vector<int> &nums, int left, int right, vector<vector<int>> &memo)
    {
        if (left+1 == right) return 0;
        if (memo[left][right] > 0) return memo[left][right];
        int ret = 0;
        for (int i = left+1; i < right; ++i)
            ret = max(ret, nums[i]*nums[left]*nums[right] + 
                burst(nums, left, i, memo) + burst(nums, i, right, memo));
            
        return memo[left][right] = ret;
    }
};
