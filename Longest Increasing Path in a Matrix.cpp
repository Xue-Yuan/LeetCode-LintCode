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

class Solution 
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                dp[i][j] = dfs(matrix, i, j, dp, 0, nullptr);
                res = max(res, dp[i][j]);
            }
        return res;
    }
    
private:
    int dfs(vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &dp, int cnt, int *last)
    {
        if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || dp[r][c] == VISITED) return cnt;
        if (last && *last <= matrix[r][c]) return cnt;
        
        if (dp[r][c] > 0) return cnt + dp[r][c];
        
        ++cnt;
        dp[r][c] = VISITED;
        int res = 0;
        res = max(res, dfs(matrix, r - 1, c, dp, cnt, &matrix[r][c]));
        res = max(res, dfs(matrix, r + 1, c, dp, cnt, &matrix[r][c]));
        res = max(res, dfs(matrix, r, c + 1, dp, cnt, &matrix[r][c]));
        res = max(res, dfs(matrix, r, c - 1, dp, cnt, &matrix[r][c]));
        dp[r][c] = -1;
        
        return res;
    }
    const int VISITED = -2;
};
