/*
	Given a m x n grid filled with non-negative numbers, find a path 
		from top left to bottom right which minimizes the sum of all 
		numbers along its path.

	Note: You can only move either down or right at any point in time.
*/

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < grid.size(); ++i)
            grid[i][0] += grid[i-1][0];
        for(int j = 1; j < grid[0].size(); ++j)
            grid[0][j] += grid[0][j-1];
        for(int i = 1; i < grid.size(); ++i)
            for(int j = 1; j < grid[0].size(); ++j)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        return grid[m-1][n-1];
    }
};

//If we don't want to modify the original matrix
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if (grid.empty() || grid[0].empty()) return 0;
        
        vector<int> dp(grid[0].size(), 0);
        dp[0] = grid[0][0];
        
        for (size_t c = 1; c < grid[0].size(); ++c)
            dp[c] = dp[c - 1] + grid[0][c];
            
        for (size_t r = 1; r < grid.size(); ++r)
        {
            dp[0] += grid[r][0];
            for (size_t c = 1; c < grid[0].size(); ++c)
                dp[c] = min(dp[c - 1], dp[c]) + grid[r][c];
        }
                
        return dp.back();
    }
};
