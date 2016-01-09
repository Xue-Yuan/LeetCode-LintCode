/*
    Find all possible combinations of k numbers that add up to a 
        number n, given that only numbers from 1 to 9 can be used 
        and each combination should be a unique set of numbers.

    Ensure that numbers within the set are sorted in ascending order.


    Example 1:

        Input: k = 3, n = 7

        Output: [[1,2,4]]

    Example 2:

        Input: k = 3, n = 9

        Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> path;
        vector<vector<int>> ret;
        combinationSum3(1, k, n, path, ret);
        return ret;
    }
    
    void combinationSum3(int cur, int k, int n, vector<int> &path, vector<vector<int>> &ret)
    {
        if (n == 0 && k == 0)
        {
            ret.push_back(path);
            return;
        }
        
        for (int i = cur; i < 10; ++i)
        {
            if (n - i < 0) break;
            path.push_back(i);
            combinationSum3(i + 1, k - 1, n - i, path, ret);
            path.pop_back();
        }
    }
};