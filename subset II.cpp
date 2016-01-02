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

//DFS
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

//iteration
class Solution 
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) 
    {
        vector<vector<int>> res(1);
        res.reserve(1 << S.size());
        sort(S.begin(),S.end());
        size_t presz = 0;
        for(int i=0;i<S.size();i++)
        {
            int sz = res.size();
            for (int j = 0; j < sz; ++j) 
            {
                if(i == 0 || S[i] != S[i-1] || j >= presz)
                {
                    res.push_back(res[j]);
                    res.back().push_back(S[i]);
                }
            }
            presz = sz;
        }
        return res;
    }
};


