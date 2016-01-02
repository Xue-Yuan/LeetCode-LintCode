/*
    Given two integers n and k, return all possible combinations of k 
        numbers out of 1 ... n.

    For example,
        If n = 4 and k = 2, a solution is:

        [
          [2,4],
          [3,4],
          [2,3],
          [1,2],
          [1,3],
          [1,4],
        ]
*/

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ret;
        vector<int> path;
        combine(1, k, n, path, ret);
        return ret;
    }
    
    void combine(int cur, int remain, int &n, vector<int> &path, vector<vector<int>> &ret)
    {
        if (remain == 0)
        {
            ret.push_back(path);
            return;
        }
        
        for (int i = cur; i <= n + 1 - remain; ++i)
        {
            path.push_back(i);
            combine(i + 1, remain - 1, n, path, ret);
            path.pop_back();
        }
    }
};