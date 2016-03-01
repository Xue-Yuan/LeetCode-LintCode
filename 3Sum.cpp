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
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) 
    {
        // write your code here
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int left = i + 1, right = (int)nums.size() - 1; left < right;)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) right--;
                else if (sum < 0) left++;
                else 
                {
                    ret.push_back({nums[i], nums[left++], nums[right--]});
                    while (left < right && nums[left] == nums[left - 1]) left++;
                }
            }
        }
        return ret;
    }
};


