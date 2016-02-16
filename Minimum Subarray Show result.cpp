/*
    Given an array of integers, find the subarray with smallest sum.

    Return the sum of the subarray.

    Example
        For [1, -1, -2, 1], return -3

    Note
        The subarray should contain at least one integer.
*/

class Solution {
public:
    int minSubArray(vector<int> nums) {
        if (nums.empty()) return 0;
        int sum = 0, res = nums.front();
        for (int &i : nums)
        {
            sum = min(sum+i, i);
            res = min(res, sum);
        }
        return res;
    }
};
