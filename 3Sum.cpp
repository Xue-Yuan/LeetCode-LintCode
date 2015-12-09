/*
    Given an array S of n integers, are there elements a, b, c in S 
        such that a + b + c = 0? Find all unique triplets in the array
         which gives the sum of zero.

    Note:
        Elements in a triplet (a,b,c) must be in non-descending order. 
            (ie, a ≤ b ≤ c)
        The solution set must not contain duplicate triplets.
            
        For example, given array S = {-1 0 1 2 -1 -4},

            A solution set is:
            (-1, 0, 1)
            (-1, -1, 2)
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        if (nums.size() < 3) return {};
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ret;
        for (int i = 0; i <= nums.size() - 3; ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int remain = 0 - nums[i];
            int left = i + 1, right = (int)nums.size() - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] < remain)
                    ++left;
                else if (nums[left] + nums[right] > remain)
                    --right;
                else
                {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left + 1] == nums[left]) ++left;
                    while(left < right && nums[right - 1] == nums[right]) --right;
                    ++left;
                    --right;
                }
            }
        }
        return ret;        
    }
};