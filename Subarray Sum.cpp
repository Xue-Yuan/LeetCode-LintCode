/*
    Given an integer array, find a subarray where the sum of numbers 
        is zero. Your code should return the index of the first number 
        and the index of the last number.

    Example
        Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].

    Note
        There is at least one subarray that it's sum equals to zero.
*/

// If sum(0 ~ i) == sum (0 ~ j), then sum(i+1, j) == 0
class Solution 
{
public:
    vector<int> subarraySum(vector<int> nums)
    {
        //sum and idx pair
        unordered_map<int, size_t> m;
        m[0] = -1;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (m.find(sum) != m.end()) return {m[sum] + 1, i};
            m[sum] = i;
        }
        return {-1, -1};
    }
};
