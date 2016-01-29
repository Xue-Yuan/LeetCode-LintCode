/*
    Given an array with n objects colored red, white or blue, sort 
        them so that objects of the same color are adjacent, with 
        the colors in the order red, white and blue.

    Here, we will use the integers 0, 1, and 2 to represent the color 
        red, white, and blue respectively.
*/

//https://en.wikipedia.org/wiki/Dutch_national_flag_problem#Pseudocode
// n: the bottom of the top
// i: the top of the bottom
// j: the top of the middle
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int i = 0, j = 0, n = (int)nums.size() - 1;
        int mid = 1;
        while (j <= n)
        {
            if (nums[j] < mid) swap(nums[j++], nums[i++]);
            else if (nums[j] > mid) swap(nums[j], nums[n--]);
            else j++;
        }
    }
};
