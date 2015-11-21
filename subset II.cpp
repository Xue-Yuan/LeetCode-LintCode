/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

#include <vector>

using std::vector;

class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> v = {};
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, v, 0, ret);
        return ret;
    }
    void subsetsWithDup(vector<int> &nums, vector<int> &v, int beg, vector<vector<int>> &ret)
    {
        ret.push_back(v);
        for(int i = beg; i < nums.size(); ++i)
        {
            if(i == beg || nums[i] != nums[i-1])        //eliminate duplications
            {
                v.push_back(nums[i]);
                subsetsWithDup(nums, v, i + 1, ret);
                v.pop_back();
            }
        }
    }
};