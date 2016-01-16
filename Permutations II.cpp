/*
    Given a collection of numbers that might contain duplicates, return 
        all possible unique permutations.

    For example,
        [1,1,2] have the following unique permutations:
        [1,1,2], [1,2,1], and [2,1,1].
*/

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        permuteUnique(nums, 0, ret);
        return ret;
    }
private:
    //pass by value
    void permuteUnique(vector<int> nums, int beg, vector<vector<int>> &ret)
    {
        if (beg == nums.size())
        {
            ret.push_back(nums);
            return;
        }
        
        for (int i = beg; i < nums.size(); ++i)
        {
            if (i != beg && nums[i] == nums[beg]) continue;
            swap(nums[i], nums[beg]);
            permuteUnique(nums, beg + 1, ret);
        }
    }
};

//not in monotonic order.
class Solution2
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        permuteUnique(nums, 0, ret);
        return ret;
    }
private:
    //pass py reference
    void permuteUnique(vector<int> &nums, int beg, vector<vector<int>> &ret)
    {
        if (beg == nums.size())
        {
            ret.push_back(nums);
            return;
        }
        
        for (int i = beg; i < nums.size(); ++i)
        {
            if (i == beg || (nums[i] != nums[beg] && nums[i] != nums[i - 1])
            {
                swap(nums[i], nums[beg]);
                permuteUnique(nums, beg + 1, ret);
                swap(nums[i], nums[beg]);
            }
        }
    }
};
