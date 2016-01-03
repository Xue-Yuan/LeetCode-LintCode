/*
    Given a set of candidate numbers (C) and a target number (T), find 
        all unique combinations in C where the candidate numbers sums to T.

    The same repeated number may be chosen from C unlimited number of times.

    Note:
        All numbers (including target) will be positive integers.

        Elements in a combination (a1, a2, … , ak) must be in non-descending 
            order. (ie, a1 ≤ a2 ≤ … ≤ ak).

        The solution set must not contain duplicate combinations.
        
        For example, given candidate set 2,3,6,7 and target 7, 
        
        A solution set is: 
            [7] 
            [2, 2, 3] 
*/

class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> ret;
        combinationSum(candidates, target, 0, path, ret);
        return ret;
    }
    
    void combinationSum(vector<int> &candidates, int target, int idx, vector<int> &path, vector<vector<int>> &ret)
    {
        if (target == 0)
        {
            ret.push_back(path);
            return;
        }
        
        for (int i = idx; i < candidates.size(); ++i)
        {
            if (target - candidates[i] < 0) break;
            path.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, path, ret);
            path.pop_back();
        }
    }
};
