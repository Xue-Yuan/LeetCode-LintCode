/*
    Given a collection of numbers, return all possible permutations.

    For example,
    [1,2,3] have the following permutations:
    [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        if(nums.empty()) return {};
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        ret.push_back(nums);
        
        while(true)
        {   
        	int m = -1;
            for(int i = 0; i < nums.size() - 1; ++i)
                if(nums[i] < nums[i + 1])
                    m = i;
            if(m == -1)
            	break;
            int l = -1;
            for(int i = m + 1; i < nums.size(); ++i)
                if(nums[i] > nums[m])
                    l = i;
            swap(nums[m], nums[l]);
            reverse(nums.begin() + m + 1, nums.end());
            ret.push_back(nums);
        }
        return ret;
    }
};

class Solution2
{
private:
    //pass by value. The result is in monotonic order.
    void recursion(vector<int> nums, int beg, vector<vector<int>> &res) 
    {
        if (beg == nums.size()) 
        {
            res.push_back(nums);
            return;
        }
        for (int i = beg; i < nums.size(); i++) 
        {
            swap(nums[i], nums[beg]);
            recursion(nums, beg + 1, res);
        }
    }
public:
    vector<vector<int> > permute(vector<int> &nums) 
    {
        vector<vector<int>> res;
        recursion(nums, 0, res);
        return res;
    }
};