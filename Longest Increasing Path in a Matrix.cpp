/*
    Given an integer matrix, find the length of the longest increasing path.

    From each cell, you can either move to four directions: left, right, up 
        or down. You may NOT move diagonally or move outside of the boundary 
        (i.e. wrap-around is not allowed).

    Example 1:

        nums = [
          [9,9,4],
          [6,6,8],
          [2,1,1]
        ]
        Return 4
        The longest increasing path is [1, 2, 6, 9].

    Example 2:

        nums = [
          [3,4,5],
          [3,2,6],
          [2,2,1]
        ]
        Return 4
        The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        memo.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        r = (int)matrix.size(), c = (int)matrix[0].size();
        
        int ret = 1;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                ret = max(ret, dfs(matrix, i, j, nullptr));
        
        return ret;
    }
private:
    int dfs(vector<vector<int>> &m, int x, int y, int *pre)
    {
        if (x<0 || x>=r || y<0 || y>=c) return 0;
        if (pre && m[x][y] >= *pre) return 0;
        if (memo[x][y] > 0) return memo[x][y];
        
        int ret = 0;
        pre = &m[x][y];
        ret = max(ret, dfs(m, x+1, y, pre));
        ret = max(ret, dfs(m, x-1, y, pre));
        ret = max(ret, dfs(m, x, y+1, pre));
        ret = max(ret, dfs(m, x, y-1, pre));
        
        return memo[x][y] = ret + 1;
    }    
private:
    vector<vector<int>> memo;
    int r, c;
};
