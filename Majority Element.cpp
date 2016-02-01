/*
    Given an array of size n, find the majority element. The 
        majority element is the element that appears more than 
        ⌊ n/2 ⌋ times.

    You may assume that the array is non-empty and the majority 
        element arraylways exist in the array.
*/

//voting algorithm
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        int cnt = 0, cur;
        for(int &n : nums)
        {
            if(n == cur) cnt++;
            else if (--cnt <= 0)
            {
                cur = n;
                cnt = 1;
            }
        }
        return cur;
    }
};
