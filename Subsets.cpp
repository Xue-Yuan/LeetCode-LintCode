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

//kinda the same idea as the bit manipulation solution.
class Solution2
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        ret.reserve(1 << nums.size());
        vector<int> path;
        subsets(nums, 0, path, ret);
        return ret;
    }
    
    void subsets(vector<int> &nums, int cur, vector<int> &path, vector<vector<int>> &ret)
    {
        if (cur == nums.size())
        {
            ret.push_back(path);
            return;
        }
        
        subsets(nums, cur + 1, path, ret);
        path.push_back(nums[cur]);
        subsets(nums, cur + 1, path, ret);
        path.pop_back();
    }
};

//DFS
class Solution3
{
public:
    vector<vector<int>> subsets(vector<int> &nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.reserve(1 << nums.size());
        vector<int> vec;
        subsets(nums, vec, 0, res);
        return res;
    }
private:
    void subsets(vector<int> &nums, vector<int> &vec, int begin, vector<vector<int> > &res) 
    {
        res.push_back(vec);
        for (int i = begin; i != nums.size(); ++i) 
        {
            vec.push_back(nums[i]);
            subsets(nums, vec, i + 1, res);
            vec.pop_back();
        }
    }
};

class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {
        int sz = S.size();
        vector<vector<int>> res;
        res.reserve(1 << s.size());
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size(); ++i) 
        {
            int sz = res.size();
            for (int j = 0; j < sz; ++j) 
            {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};

