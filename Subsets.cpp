/*
    Given a set of distinct integers, nums, return all possible subsets.

    Note:
        Elements in a subset must be in non-descending order.
            The solution set must not contain duplicate subsets.
    
    For example,
        If nums = [1,2,3], a solution is:
            [
              [3],
              [1],
              [2],
              [1,2,3],
              [1,3],
              [2,3],
              [1,2],
              []
            ]
*/

//bit manipulation
class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        unsigned size = 1 << nums.size();
        vector<vector<int>> ret;
        ret.reserve(size);
        for (unsigned taken = 0; taken < size; ++taken)
        {
            vector<int> path;
            for (int i = 0; i < nums.size(); ++i)
                if ((taken >> i) & 0x1) path.push_back(nums[i]);
            ret.push_back(move(path));
        }
        return ret;
    }
};

class Solution2
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        ret.reserve(1 << nums.size());
        subsets(nums, 0, {}, ret);
        return ret;
    }
    //pass by value.
    void subsets(vector<int> &nums, int cur, vector<int> path, vector<vector<int>> &ret)
    {
        if (cur == nums.size())
        {
            ret.push_back(path);
            return;
        }
        
        subsets(nums, cur + 1, path, ret);
        path.push_back(nums[cur]);
        subsets(nums, cur + 1, path, ret);
    }
};
