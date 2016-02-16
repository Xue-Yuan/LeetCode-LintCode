/*
    Given a collection of candidate numbers (C) and a target number (T), 
        find all unique combinations in C where the candidate numbers 
        sums to T.

    Each number in C may only be used once in the combination.

    Example
        Given candidate set [10,1,6,7,2,1,5] and target 8,

        A solution set is:

        [
          [1,7],
          [1,2,5],
          [2,6],
          [1,1,6]
        ]
    Note
        All numbers (including target) will be positive integers.
        Elements in a combination (a1, a2, … , ak) must be in 
            non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        The solution set must not contain duplicate combinations.
*/

class Solution {
private:
    using VIT = vector<int>::iterator;
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        dfs(num.begin(), num.end(), target);
        return ret;
    }
private:
    void dfs(VIT vb, VIT ve, int target)
    {
        if (target < 0) return;
        if (target == 0)
        {
            ret.push_back(path);
            return;
        }

        for (VIT cur = vb; cur != ve; ++cur)
            if (cur == vb || *cur != *(cur-1))
            {
                path.push_back(*cur);
                dfs(cur+1, ve, target - *cur);
                path.pop_back();
            }
    }
};
