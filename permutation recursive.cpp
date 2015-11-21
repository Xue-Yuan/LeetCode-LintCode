#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> permutation(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        permutation(nums, 0, ret);
        return ret;
    }

    void permutation(vector<int> &nums, int beg, vector<vector<int>> &ret)
    {
        if(beg == nums.size()-1)
        {
            ret.push_back(nums);
            return;
        }
        for(int i = beg; i < nums.size(); ++i)
        {
            vector<int> tmp = nums;
            if(i == beg || nums[i] != nums[i-1])    //handle duplicates
            {
                swap(nums[beg], nums[i]);
                sort(nums.begin()+beg+1, nums.end());
                permutation(nums, beg + 1, ret);
                nums = tmp;
            }
        }
    }
};